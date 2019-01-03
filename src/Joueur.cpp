#include "Joueur.h"
#include "Arme.h"
#include "Zombie.h"
#include <assert.h>
#include <iostream>

using namespace std;

Joueur::Joueur() : Humanoide()
{
	//hp = 100;
	//position = Vec2(0.0,0.0);
	//vitesse = Vec2(0.0,0.0);
	//acceleration = Vec2(0.0,0.0);
	//arme = Arme("Pistolet",15,120,120,12,3.5,1.25);
	//arme.chargerArme("data/armes/armes.txt");
}

void Joueur::setArme(Arme _arme)
{
	arme = _arme;
}

Arme Joueur::getArme()
{
	return arme;
}

Joueur::~Joueur()
{

}

bool Joueur::toucheZombie (Zombie & Z)
{
	return ((position - Z.getPosition()).mod()<= collision.getRayon()+Z.getCollision().getRayon());
}

void Joueur::toucheBord(double Xmin, double Xmax, double Ymin, double Ymax)
{
	if(position.getX() < Xmin + collision.getRayon())
	{
		setPosition(Vec2(Xmin + collision.getRayon(),position.getY()));
		setVitesse(Vec2(- vitesse.getX(), vitesse.getY()));
	}
	if(position.getX() > Xmax - collision.getRayon())
	{
		setPosition(Vec2(Xmax - collision.getRayon(), position.getY()));
		setVitesse(Vec2(- vitesse.getX(), vitesse.getY()));
	}
	if(position.getY() < Ymin + collision.getRayon())
	{
		setPosition(Vec2(position.getX(), Ymin + collision.getRayon()));
		setVitesse(Vec2(getVitesse().getX(),- getVitesse().getY()));
	}
	if(position.getY() > Ymax - collision.getRayon())
	{
		setPosition(Vec2(position.getX(), Ymax - collision.getRayon()));
		setVitesse(Vec2(getVitesse().getX(),- getVitesse().getY()));
	}
}




ostream& operator<< (ostream& flux, Joueur& joueur)
{
	Vec2 position = joueur.getPosition();
	flux << "(Joueur : Vie " << joueur.getHp() << ", Position " << position << ")";
	return flux;
}
