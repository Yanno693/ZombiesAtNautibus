
#include "Jeu.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

/*
ETAT :
0 => menu
1 => enJeu
2 => enPause
3 => GameOver

*/

bool Jeu::enPause()
{
	return (etat == 2);
}

Jeu::Jeu()
{
	joueur = Joueur();
  	score = 0;
  	manche = 0;
  	nbZombies = 0;
  	etat = 0;
  	curseur = Vec2(0.0,0.0);
  	Xwin = 0;
  	Ywin = 0;
  	zombiesTues = 0;
}

Jeu::~Jeu()
{
	delete [] armes;
}

void Jeu::setJoueur(Joueur _joueur)
{
  joueur = _joueur;
}
void Jeu::setCurseur(Vec2 _curseur)
{
  curseur = _curseur;
}
void Jeu::setScore(int _score)
{
  score = _score;
}
void Jeu::setManche(int _manche)
{
  manche = _manche;
}
void Jeu::setEtat(int _etat)
{
	if(_etat < 4)
	{
		etat = _etat;
	}
}

void Jeu::setZombies(vector<Zombie *> _zombies)
{
  zombies = _zombies;
}

Joueur Jeu::getJoueur()
{
  return joueur;
}
Vec2 Jeu::getCurseur()
{
  return curseur;
}
int Jeu::getScore(){
  return score;
}
int Jeu::getManche()
{
  return manche;
}
bool Jeu::getEnPause()
{
	return enPause();
}
int Jeu::getEtat()
{
	return etat;
}

int Jeu::getnbZombies(){
  return nbZombies;
}

int Jeu::getHpZombies()
{
	return hpZombies;
}

int Jeu::getZombiesTues()
{
	return zombiesTues;
}

vector<Zombie *> Jeu::getZombies(){
  return zombies;
}

vector<Objet> Jeu::getObjets(){
  return objets;
}

Zombie * Jeu::getZombie(unsigned int i)
{
	return zombies[i];
}

void Jeu::chargerArmes()
{
	string chemin = "data/armes/armes.txt";

	armes = new Arme[8];

	string nom;
	int degat, munitionMax, tailleChargeur;
	float tempsRechargement, vitesse;

	ifstream fichier;
	fichier.open(chemin.c_str());

	if(!fichier.is_open())
	{
		cout << "Erreur de chargement de l'arme" << endl;
		exit(1);
	}

	for(int i = 0; i < 8; i++)
	{
		fichier >> nom >> degat >> munitionMax >> tailleChargeur >> tempsRechargement >> vitesse;

		armes[i].setNom(nom);
		armes[i].setDegat(degat);
		armes[i].setMunitionMax(munitionMax);
		armes[i].setTailleChargeur(tailleChargeur);
		armes[i].setTempsRechargement(tempsRechargement);
		armes[i].setVitesse(vitesse);

		armes[i].setMunition(munitionMax);
		armes[i].setMunitionChargeur(tailleChargeur);
	}

	fichier.close();
}

void Jeu::initialisation(int _Xwin, int _Ywin)
{
	Xwin = _Xwin;
	Ywin = _Ywin;
	score = 0;
	etat = 1;
	zombiesTues = 0;
	nbZombies = 0;
	manche = 0;
	zombies.clear();
	objets.clear();

	chargerArmes();

	joueur.setPosition(Vec2(400,400));
	joueur.setCollision(Cercle(Vec2(400,400),25.0));
	joueur.setAcceleration(Vec2(0,0));
	joueur.setVitesse(Vec2(0,0));
	joueur.setHp(100);

	joueur.setArme(armes[0]);
}

void Jeu::nouvelleManche ()
{
  	manche += 1;
  	majZombies();
}

void Jeu::ajoutZombies(int rand)
{
	if(etat == 1)
	{
		float r = ((float)(rand % 2000)/1000.0) - 1.0;

		Vec2 pos;
		pos.setExp(M_PI*r,1.5*(Xwin/2.0));

		zombies.push_back(new Zombie());
		zombies[zombies.size() - 1]->setPosition( Vec2(Xwin/2,Ywin/2) + pos);
		zombies[zombies.size() - 1]->setDegat(degatZombies);
		zombies[zombies.size() - 1]->setHp(hpZombies);
		nbZombies-=1;
	}
}

void Jeu::majZombies()
{
	nbZombies = 9*log(manche+1);
	degatZombies = manche;
  	hpZombies = log(manche)*20+30;
	vitesseZombies = log(manche + 1)/6.0;
}

void Jeu::lacherObjet(Zombie * z, int rand)
{
	if(rand % 200 < 20)
	{		
		int obj = rand % 10;
		
		Cercle c(z->getPosition(),z->getCollision().getRayon());
		Objet o(obj,c);
		
		objets.push_back(o);
	}
}

int Jeu::recupererObjet()
{

	int id = -1;

	for(unsigned int i = 0; i < objets.size(); i++)
	{		
		if((joueur.getPosition() - objets[i].getPosition()).mod() < joueur.getCollision().getRayon() + objets[i].getRayon())
		{
			id = objets[i].getId();
			
			if(id < 8)
			{
				joueur.setArme(armes[id]);
			}
			else if(id == 8)
			{
				int hp = joueur.getHp() + 25;
				
				if(hp < 100)
				{
					joueur.setHp(hp);
				}
				else
				{
					joueur.setHp(100);
				}
			}
			else if(id == 9)
			{
				Arme a = joueur.getArme();
				a.setMunition(a.getMunitionMax());
				joueur.setArme(a);
			}
			
			objets.erase(objets.begin()+i);
		}
	}
	
	return id;

}

void Jeu::inertieJoueur()
{
	if(etat == 1)
	{
		joueur.setAcceleration(Vec2(0.0,0.0) - joueur.getVitesse()*0.25);
	}
}

void Jeu::haut()
{
	if(etat == 1)
	{
		joueur.setAcceleration(joueur.getAcceleration() + Vec2(0,-1));
	}
}

void Jeu::bas()
{
	if(etat == 1)
	{
		joueur.setAcceleration(joueur.getAcceleration() + Vec2(0,1));
	}
}

void Jeu::gauche()
{
	if(etat == 1)
	{
		joueur.setAcceleration(joueur.getAcceleration() + Vec2(-1,0));
	}
}

void Jeu::droite()
{
	if(etat == 1)
	{
		joueur.setAcceleration(joueur.getAcceleration() + Vec2(1,0));
	}
}

void Jeu::deplacementJoueur()
{
	if(etat == 1)
	{
		joueur.toucheBord(0.0,Xwin,0.0,Ywin);
		joueur.setVitesse(joueur.getVitesse() + joueur.getAcceleration());
		joueur.setPosition(joueur.getPosition() + joueur.getVitesse());
	}
}

void Jeu::deplacementZombies()
{
	if(etat == 1)
	{
		for(unsigned int i = 0; i < zombies.size(); i++)
		{
			zombies[i]->setCible(joueur.getPosition());
			zombies[i]->setAcceleration(Vec2(0.0,0.0) - zombies[i]->getVitesse()*0.25);

			Vec2 acc;
			acc.setExp((zombies[i]->getCible() - zombies[i]->getPosition()).arg(),2);

			zombies[i]->setAcceleration(zombies[i]->getAcceleration() + acc*vitesseZombies);
			zombies[i]->setVitesse(zombies[i]->getVitesse() + zombies[i]->getAcceleration());
			zombies[i]->setPosition(zombies[i]->getPosition() + zombies[i]->getVitesse());

			if(joueur.toucheZombie(*zombies[i]))
			{
				joueur.setVitesse(joueur.getVitesse() + acc*10);
				zombies[i]->setVitesse(zombies[i]->getVitesse() - acc*5);
				joueur.prendreDegat(zombies[i]->getDegat());
			}
		}

		if(etat != 3)
		{
			if(!joueur.estVivant())
			{
			  etat = 3;
			}
		}
	}
}

void Jeu::recharger()
{
	if(etat == 1)
	{
		Arme a  = joueur.getArme();
      	a.recharger();
    	joueur.setArme(a);
	}
}

bool Jeu::tire(int rand)
{
	if(etat == 1)
	{
		if((joueur.getArme().getMunitionChargeur() > 0))
	  	{

			Arme a  = joueur.getArme();
			a.tirer();
			joueur.setArme(a);

	  		Vec2 vec_tire = curseur - joueur.getPosition();
			Vec2 vec_zombie;
			int zombie_proche = -1;
			for(int i = zombies.size() - 1; i >= 0; i--)
	  		{
	  			vec_zombie = zombies[i]->getPosition() - joueur.getPosition();

	  			if(vec_tire.angle(vec_zombie) < 1.0 && vec_tire.angle(vec_zombie) > -1.0)
	  			{
	  				double rayon = zombies[i]->getCollision().getRayon();

	  				double JS = vec_tire.mod();
	  				double SZ = (curseur - zombies[i]->getPosition()).mod();
	  				double ZJ = vec_zombie.mod();

	  				double p = (JS + SZ + ZJ)/2.0;
	  				double aire = sqrt(p*(p - JS)*(p - SZ)*(p - ZJ));
	  				double hauteur = (2.0 * aire )/JS;

	  				if(hauteur <= rayon)
	  				{
		      			if (zombie_proche == -1)
						{
							zombie_proche = i;
						}
						else if(Vec2(zombies[zombie_proche]->getPosition() - joueur.getPosition()).mod() > vec_zombie.mod())
						{
							zombie_proche = i;
						}
	  				}
	  			}
	  		}
	  		
			if(zombie_proche != -1)
			{
		    	zombies[zombie_proche]->prendreDegat(joueur.getArme().getDegat());

		    	Vec2 push;
		    	push.setExp(vec_tire.arg(), sqrt((float)joueur.getArme().getDegat()));

		    	zombies[zombie_proche]->setVitesse(zombies[zombie_proche]->getVitesse() + push);

		    	if(!zombies[zombie_proche]->estVivant())
		    	{
		    		lacherObjet(zombies[zombie_proche], rand);
		    		zombies.erase(zombies.begin()+zombie_proche);
		    		augmenterScore(100*manche);
		    		zombiesTues += 1;
		    	}
			}
			return true;
	  	}
	  	else
	  	{
	  		Arme a  = joueur.getArme();
	  		a.recharger();
	  		joueur.setArme(a);
			return false;
	  	}
	}
	else
	{
		return false;
	}
}

void Jeu::pause()
{
	if(etat == 1)
	{
		etat = 2;
	}
	else if(etat == 2)
	{
		etat = 1;
	}
}

void Jeu::augmenterScore(int s)
{
	score += s;
}
