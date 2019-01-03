#include "Humanoide.h"
#include "Vec2.h"
#include "Cercle.h"
#include <vector>


#include<assert.h>
#include<iostream>

using namespace std;

Humanoide::Humanoide()
{
	hp = 100;
	vivant = true;
	position = Vec2(0.0,0.0);
	vitesse = Vec2(0.0,0.0);
	acceleration = Vec2(0.0,0.0);
	collision = Cercle(position,25.0);
}

Humanoide::~Humanoide()
{

}

void Humanoide::setHp(int _hp)
{
	hp = _hp;
	if (hp <= 0) 
	{
		vivant = false;
	}
	else
	{
		vivant = true;
	}
}

void Humanoide::setPosition(Vec2 _position)
{
	position = _position;
}

void Humanoide::setVitesse(Vec2 _vitesse)
{
	vitesse = _vitesse;
}

void Humanoide::setAcceleration(Vec2 _acceleration)
{
	acceleration = _acceleration;
}

void Humanoide::setCollision(Cercle _collision)
{
	collision = _collision;
}

int Humanoide::getHp()const
{
	return hp;
}

Vec2 Humanoide::getPosition()const
{
	return position;
}

Vec2 Humanoide::getVitesse()const
{
	return vitesse;
}

Vec2 Humanoide::getAcceleration()const
{
	return acceleration;
}

Cercle Humanoide::getCollision()const
{
	return collision;
}

bool Humanoide::estVivant()const{
	return vivant;
}

void Humanoide::prendreDegat(int degat){
	hp -= degat;
	if(hp <= 0)
	{
		vivant = false;
	}
}
