#include "Texte.h"
#include <iostream>
using namespace std;

Texte::Texte()
{
    x = 0;
    y = 0;
    dimX = 0;
    dimY = 0;

    couleur->r = 0;
   	couleur->g = 0;
   	couleur->b = 0;
}

Texte::Texte(string _cheminPolice, string _texte, SDL_Renderer * _renderer)
{
	renderer =  _renderer;

	cheminPolice = _cheminPolice;
    texte = _texte;

    x = 0;
    y = 0;
    dimX = 0;
    dimY = 0;


    couleur = new SDL_Color;
	couleur->r = 0;
   	couleur->g = 0;
   	couleur->b = 0;

   	police = TTF_OpenFont(cheminPolice.c_str(),64);
    if(!police)
    {
    	cout << "Erreur chargement de la police de caractères." << endl;
    }
    else
    {
    	surface = TTF_RenderText_Solid(police,texte.c_str(),*couleur);
    	texture = SDL_CreateTextureFromSurface(renderer,surface);
    }
}

Texte::~Texte()
{
	if(police)
	{
		TTF_CloseFont(police);
	}
	if(surface)
	{
		SDL_FreeSurface(surface);
	}
	if(texture)
	{
		SDL_DestroyTexture(texture);
	}
	
	delete couleur;
}

void Texte::setTexte(string _texte)
{
   texte = _texte;
   
   SDL_FreeSurface(surface);
   SDL_DestroyTexture(texture);

   surface = TTF_RenderText_Solid(police,texte.c_str(),*couleur);
   texture = SDL_CreateTextureFromSurface(renderer,surface);

}

void Texte::setCouleur (unsigned int _r, unsigned int _g, unsigned int _b)
{
	couleur->r = _r;
	couleur->g = _g;
	couleur->b = _b;
	
	SDL_FreeSurface(surface);
   	SDL_DestroyTexture(texture);

	surface = TTF_RenderText_Solid(police,texte.c_str(),*couleur);
  	texture = SDL_CreateTextureFromSurface(renderer,surface);
}

void Texte::setPosition(int _x,int _y)
{
	x = _x;
	y = _y;
}

void Texte::setDimension(int _dimX,int _dimY)
{
	dimX = _dimX;
	dimY = _dimY;
}


void Texte::afficher()
{
	if(surface && texture)
	{
		SDL_RenderCopyEx(renderer,texture,NULL,rect,0.0,NULL,SDL_FLIP_NONE);
	}
}

void Texte::afficher(SDL_Rect * _rect)
{
	if(surface && texture)
	{
		SDL_RenderCopyEx(renderer,texture,NULL,_rect,0.0,NULL,SDL_FLIP_NONE);
	}
}
