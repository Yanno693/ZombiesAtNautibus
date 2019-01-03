#ifndef JEU_H
#define JEU_H

#include<iostream>
#include "Joueur.h"
#include "Vec2.h"
#include "Zombie.h"
#include "Objet.h"
#include <vector>

using namespace std;

/*
ETAT :
0 => menu
1 => enJeu
2 => enPause
3 => GameOver

*/

/**
@class Jeu
@brief Une structure qui contient toutes les données d'une partie en cours
*/
class Jeu
{
  private:
    Joueur joueur;
    Vec2 curseur;
    int score;
    int manche;

    int nbZombies;
    int degatZombies;
    int hpZombies;
    int zombiesTues;
    float vitesseZombies;

    int etat;
    vector<Zombie *> zombies;
    Arme* armes;
    vector<Objet> objets;
    int Xwin;
    int Ywin;

    void chargerArmes();
    void majZombies();
    void lacherObjet(Zombie * z, int rand);
    bool enPause();
  public:
  
  	/**
  	@brief Constructeur de Jeu (Sans paramètres)
  	*/
    Jeu();
    
    /**
  	@brief Destructeur de Jeu (Sans paramètres)
  	*/
    ~Jeu();

	/**
  	@brief Definir le joueur de la partie
  	@param _joueur Le Joueur
  	*/
    void setJoueur(Joueur _joueur);
    
    /**
  	@brief Definir la position du curseur
  	@param _curseur Position (x,y) du curseur
  	*/
    void setCurseur(Vec2 _curseur);
    
    /**
  	@brief Definir le score de la partie
  	@param _score Le score
  	*/
    void setScore(int _score);
    
    /**
  	@brief Definir la manche de la partie
  	@param _manche la manche
  	*/
    void setManche(int _manche);
    
    /**
  	@brief Definir l'etat de la partie
  	@param _etat Identifiant de l'etat
  	*/
    void setEtat(int _etat);
    
    /**
  	@brief Definir les zombies présents dans la partie
  	@param _zombies Liste de zombies
  	*/
    void setZombies(vector<Zombie *> _zombies);

	/**
  	@brief Acceder au Joueur de la partie
  	@return joueur
  	*/
    Joueur getJoueur();
    
    /**
  	@brief Acceder a la position du curseur
  	@return curseur
  	*/
    Vec2 getCurseur();
    
    /**
  	@brief Acceder au score de la partie
  	@return score
  	*/
    int getScore();
    
    /**
  	@brief Acceder a la manche de la partie
  	@return manche
  	*/
    int getManche();
    
    /**
  	@brief Savoir si le jeu est en pause ou pas
  	@return un booléen vrai si le jeu est en pause
  	*/
    bool getEnPause();
    
    /**
  	@brief Acceder a l'etat de la partie
  	@return etat
  	*/
    int getEtat();
    
    /**
  	@brief Acceder au nombre de Zombie dans la manche courante
  	@return nbZombies
  	*/
    int getnbZombies();
    
    /**
  	@brief Acceder au nombre de Zombie tues dans la partie
  	@return zombiesTues
  	*/
    int getZombiesTues();
    
    /**
  	@brief Acceder a la sante des Zombie dans la manche courante
  	@return hpZombies
  	*/
    int getHpZombies();
    
    /**
  	@brief Acceder a la liste des Zombie vivant dans la manche
  	@return zombies
  	*/
    vector<Zombie *> getZombies();
    
    /**
  	@brief Acceder a la liste des Objet présent dans la partie
  	@return objets
  	*/
    vector<Objet> getObjets();
    
    /**
  	@brief Acceder a un Zombie en particulier dans les Zombie vivant
  	@return zombie
  	*/
    Zombie * getZombie(unsigned int i);

	/**
  	@brief Initialise une nouvelle partie
  	@param _Xwin la largeur de la fenetre
  	@param _Ywin la hauteur de la fenetre
  	*/
    void initialisation(int _Xwin, int _Ywin);
    
    /**
  	@brief Demarre une nouvelle manche dans la partie en cours
  	*/
    void nouvelleManche();
    
    /**
  	@brief Ajoute un Zombie dans la liste des Zombie vivants
  	@param rand Un entier aléatoire
  	*/
    void ajoutZombies(int rand);

	/**
  	@brief Initie l'inertie des mouvements du Joueur
  	*/
    void inertieJoueur();
    
    /**
  	@brief Mouvement du Joueur vers le haut
  	*/
    void haut();
    
    /**
  	@brief Mouvement du Joueur vers le bas
  	*/
    void bas();
    
    /**
  	@brief Mouvement du Joueur vers la gauche
  	*/
    void gauche();
    
    /**
  	@brief Mouvement du Joueur vers la droite
  	*/
    void droite();
    
    /**
  	@brief Finalise les mouvements du Joueur
  	*/
    void deplacementJoueur();
    
    /**
  	@brief Verifier si le Joueur ramassa un Objet
  	@return L'identifiant de l'objet ramassé. -1 si aucun objet ramassé
  	*/
    int recupererObjet();
    
    /**
  	@brief Initie le déplacment des Zombie vivants
  	*/
	void deplacementZombies();
	
	/**
  	@brief Initie le tir du Joueur
  	@param rand Un entier aléatoire
  	*/
  	bool tire(int rand);
  	
  	/**
  	@brief Initie le rechargement de l'Arme du Joueur
  	*/
	void recharger();
	
	/**
  	@brief Mets le Jeu en pause ou le sort de la pause si il est deja en pause
  	*/
	void pause();
	
	/**
  	@brief Augmente le score
  	@param s Le score a ajouter
  	*/
	void augmenterScore(int s);
};

#endif
