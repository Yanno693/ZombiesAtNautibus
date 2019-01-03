#include "Zombie.h"

#include<assert.h>
#include<iostream>

using namespace std;

Zombie::Zombie() : Humanoide()
{
	//hp = 100;
	degat = 5;

	//position = Vec2(0.0,0.0);
	//vitesse = Vec2(0.0,0.0);
	//acceleration = Vec2(0.0,0.0);
	cible = Vec2(0.0,0.0);
}

Zombie::Zombie(int _degat, Vec2 _cible) : Humanoide()
{
	degat = _degat;
	cible = _cible;
}



Zombie::~Zombie()
{

}

void Zombie::setDegat(int _degat)
{
	degat = _degat;
}

void Zombie::setCible(Vec2 _cible)
{
	cible = _cible;
}

int Zombie::getDegat()const
{
	return degat;
}

Vec2 Zombie::getCible()const
{
	return cible;
}

ostream& operator<< (ostream& flux, Zombie& zombie)
{
	Vec2 position = zombie.getPosition();
	flux << "(Zombie : Vie " << zombie.getHp() << ", Position " << position << ")";
	return flux;
}
