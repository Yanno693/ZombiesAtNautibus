#include "Vec2.h"

#include<assert.h>
#include<iostream>

using namespace std;

Vec2::Vec2()
{
    x = 0.0;
    y = 0.0;
}

Vec2::Vec2(double _x, double _y)
{
    x = _x;
    y = _y;
}

double Vec2::angle(Vec2 vector)const{
  return acos( (x * vector.x + y * vector.y) / (sqrt( x*x+y*y ) * sqrt(vector.x * vector.x + vector.y * vector.y ) ) );
}

Vec2::~Vec2()
{

}

void Vec2::set(double _x, double _y)
{
    x = _x;
    y = _y;
}

void Vec2::setX(double _x)
{
    x = _x;
}

void Vec2::setY(double _y)
{
    y = _y;
}

double Vec2::getX()const
{
    return x;
}

double Vec2::getY()const
{
    return y;
}

void Vec2::setExp(double ang, double mod)
{
	x = cos(ang) * mod;
	y = sin(ang) * mod;
}

Vec2 Vec2::operator+(Vec2 v)
{
	return Vec2(x+v.getX(), y+v.getY());
}

Vec2 Vec2::operator-(Vec2 v)
{
	return Vec2(x-v.getX(), y-v.getY());
}

Vec2 Vec2::operator*(double n)
{
	return Vec2(x*n,y*n);
}

double Vec2::mod() const
{
	return sqrt(x*x+y*y);
}

double Vec2::arg() const
{
	if(mod() == 0.0)
	{
		return 0.0;
	}

	if(x != 0.0 && y == 0.0)
	{
		if(x > 0)
		{
			return 0.0;
		}
		else
		{
			return M_PI;
		}
	}

	return 2.0 * atan(y/(x + mod()));
}

void Vec2::afficher()const
{
	cout << "(" << x << "," << y << ")";
}

ostream& operator<< (ostream& flux, Vec2& v)
{
	flux << "(" << v.getX() << "," << v.getY() << ")";
	return flux;
}
