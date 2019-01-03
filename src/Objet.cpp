#include "Objet.h"

#include<assert.h>
#include<iostream>

using namespace std;

Objet::Objet()
{
	id = 0;
	collision = Cercle(Vec2(0.0,0.0),25.0);
}

Objet::Objet(int _id, Vec2 pos)
{
	id = _id;
	collision = Cercle(pos, 25.0);
}

Objet::Objet(int _id, Cercle pos)
{
	id = _id;
	collision = pos;
}

Objet::~Objet()
{

}

Vec2 Objet::getPosition() const
{
	return collision.getCentre();
}

double Objet::getRayon() const
{
	return collision.getRayon();
}

int Objet::getId() const
{
	return id;
}
