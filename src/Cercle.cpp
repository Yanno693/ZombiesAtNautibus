#include "Cercle.h"
#include "Vec2.h"

#include<assert.h>
#include<iostream>

using namespace std;



Cercle::Cercle()
{
    centre = Vec2(0.0,0.0);
    rayon = 0;
}

Cercle::Cercle(Vec2 _centre, double _rayon)
{
	centre = _centre;
	if(_rayon < 0.0)
	{
		rayon = 0.0;
	}
	else
	{
		rayon = _rayon;
	}
}

Cercle::~Cercle()
{

}

void Cercle::set(Vec2 _centre, double _rayon)
{
	centre = _centre;
	if(_rayon < 0.0)
	{
		rayon = 0.0;
	}
	else
	{
		rayon = _rayon;
	}
}

void Cercle::setCentre(Vec2 _centre)
{
	centre = _centre;
}

void Cercle::setRayon(double _rayon)
{
	if(_rayon < 0.0)
	{
		rayon = 0.0;
	}
	else
	{
		rayon = _rayon;
	}
}

Vec2 Cercle::getCentre()const
{
	return centre;
}

double Cercle::getRayon()const
{
	return rayon;
}

/*ostream& operator<< (ostream& flux, Cercle& cercle)
{
	flux << "(Rectangle : (" << r.getC1().getX() << "," << r.getC1().getY() << "),(" << r.getC2().getX() << "," << r.getC2().getY() << "))";
	return flux;
}*/
