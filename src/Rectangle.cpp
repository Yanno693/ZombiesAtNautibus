#include "Rectangle.h"
#include "Vec2.h"

#include<assert.h>
#include<iostream>

using namespace std;

Rectangle::Rectangle()
{
    c1 = Vec2(0.0,0.0);
    c2 = Vec2(0.0,0.0);

}
Rectangle::Rectangle(Vec2 _c1, Vec2 _c2)
{
    if(_c2.getX() < _c1.getX() || _c2.getY() < _c1.getY())
    {
    	c1 = Vec2(0.0,0.0);
    	c2 = Vec2(0.0,0.0);
    }
    else
    {
    	c1 = _c1;
    	c2 = _c2;
    }
}

Rectangle::~Rectangle()
{

}

void Rectangle::set(Vec2 _c1, Vec2 _c2)
{
	if(c2.getX() < c1.getX() || c2.getY() < c1.getY())
    {

    }
    else
    {
    	c1 = _c1;
    	c2 = _c2;
    }
}

void Rectangle::setC1(Vec2 _c1)
{
	if(c2.getX() < _c1.getX() || c2.getY() < _c1.getY())
    {

    }
    else
    {
    	c1 = _c1;
    }
}

void Rectangle::setC2(Vec2 _c2)
{
	if(_c2.getX() < c1.getX() || _c2.getY() < c1.getY())
    {

    }
    else
    {
    	c2 = _c2;
    }
}

Vec2 Rectangle::getC1()const
{
	return c1;
}

Vec2 Rectangle::getC2()const
{
	return c2;
}

bool Rectangle::dansRectangle(Vec2 v)
{
	return ( (v.getX() >= c1.getX()) && (v.getX() <= c2.getX()) && (v.getY() >= c1.getY()) && (v.getY() <= c2.getY()));
}

ostream& operator<< (ostream& flux, Rectangle& r)
{
	flux << "(Rectangle : (" << r.getC1().getX() << "," << r.getC1().getY() << "),(" << r.getC2().getX() << "," << r.getC2().getY() << "))";
	return flux;
}
