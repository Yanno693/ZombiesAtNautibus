#include "Image.h"

#include<iostream>

using namespace std;

Image::Image()
{
	x = 0;
	y = 0;
	dimX = 100;
	dimY = 100;
	angle = 0.0;
}

Image::Image(string _chemin, SDL_Renderer * _renderer)
{
	chemin = _chemin;
	renderer = _renderer;

	surface = IMG_Load(chemin.c_str());
	if(!surface)
	{
		cout << "Erreur pour charger l'image : " << chemin << endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer,surface);
		if(!texture)
		{
			cout << "Erreur pour charger l'image : " << chemin << endl;
		}
	}

	x = 500;
	y = 300;
	dimX = 100;
	dimY = 100;
	angle = 0;

	rect = new SDL_Rect();

	rect->x = x;
	rect->y = y;
	rect->w = dimX;
	rect->h = dimY;

}

Image::~Image()
{
	if(surface)
	{
		SDL_FreeSurface(surface);
	}
	if(texture)
	{
		SDL_DestroyTexture(texture);
	}
	
	delete rect;
}

void Image::changerPosition(int _x, int _y)
{
	x = _x;
	y = _y;

	rect->x = x;
	rect->y = y;
}

void Image::changerDimension(int _dimX, int _dimY)
{
	dimX = _dimX;
	dimY = _dimY;

	rect->w = dimX;
	rect->h = dimY;
}

void Image::changerAngle(double _angle)
{
	angle = _angle;
}

void Image::afficher()
{
	if(surface && texture)
	{
		SDL_RenderCopyEx(renderer,texture,NULL,rect,angle,NULL,SDL_FLIP_NONE);
	}
}

void Image::afficher(SDL_Rect * _rect)
{
	if(surface && texture)
	{
		SDL_RenderCopyEx(renderer,texture,NULL,_rect,angle,NULL,SDL_FLIP_NONE);
	}
}

void Image::afficherExp(SDL_Rect * _rect, double _angle)
{
	if(surface && texture)
	{
		angle = _angle;
		SDL_RenderCopyEx(renderer,texture,NULL,_rect,angle,NULL,SDL_FLIP_NONE);
	}
}

int Image::getX()const{
	return x;
}
int Image::getY()const{
	return y;
}

int Image::getdimX()const{
	return dimX;
}
int Image::getdimY()const{
	return dimY;
}
Vec2 Image::getVec()const{
	return Vec2 (x,y);
}

double Image::getAngle()const{
	return angle;
}

void Image::setX(int _x){
	x = _x;
	rect->x = x;
}
void Image::setY(int _y){
	y = _y;
	rect->y = y;
}

void Image::setAngle(double _angle){
	angle = _angle;
}
