#include <assert.h>
#include <iostream>
#include "Bouton.h"

using namespace std;

Bouton::Bouton(Vec2 _c1, Vec2 _c2, string _normal, string _focus, SDL_Renderer * _renderer) : normal(_normal,_renderer), focus(_focus,_renderer)
{
	position = Rectangle(_c1,_c2);
	renderer = _renderer;
	rect = new SDL_Rect;
	rect->x = position.getC1().getX();
	rect->y = position.getC1().getY();
	rect->w = position.getC2().getX() - position.getC1().getX();
	rect->h = position.getC2().getY() - position.getC1().getY();
}

Bouton::Bouton(Rectangle _position, string _normal, string _focus, SDL_Renderer * _renderer) : normal(_normal,_renderer), focus(_focus,_renderer)
{
	position = _position;
	renderer = _renderer;
	rect = new SDL_Rect;
	rect->x = position.getC1().getX();
	rect->y = position.getC1().getY();
	rect->w = position.getC2().getX() - position.getC1().getX();
	rect->h = position.getC2().getY() - position.getC1().getY();
}

Bouton::~Bouton()
{
	delete rect; 
}

bool Bouton::estFocus(Vec2 curseur)
{
	return position.dansRectangle(curseur);
}

void Bouton::afficher(Vec2 curseur)
{
	if(estFocus(curseur))
	{
		focus.afficher(rect);
	}
	else
	{
		normal.afficher(rect);
	}
}

