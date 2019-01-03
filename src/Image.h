#ifndef IMAGE_H
#define IMAGE_H

#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string.h>
#include<cmath>

#include "Vec2.h"

using namespace std;

/**
@class Image
@brief Une image affichable dans la fenetre principal
*/
class Image
{
    private:
		string chemin;
		SDL_Renderer * renderer;
		SDL_Surface * surface;
		SDL_Texture * texture;
		SDL_Rect * rect;
		int x;
		int y;
		int dimX;
		int dimY;
		double angle;

    public:

		/**
		@brief Constructeur d'Image (sans paramètres)
		*/
        Image();
        
		/**
		@brief Constructeur d'Image
		@param _chemin Le chemin de du fichier à charger dans l'Image et à afficher
		@param _renderer Le SDL_Renderer a relié a l'Image
		*/
        Image(string _chemin , SDL_Renderer * _renderer);

		/**
		@brief Destructeur d'Image
		*/
        ~Image();

		/**
		@brief Changer la position de l'Image
		@param _x la position en abscisse de l'Image
		@param _y la position en ordonné de l'Image
		*/
        void changerPosition(int _x, int _y);

		/**
		@brief Changer la dimension de l'Image
		@param _dimX la dimension en abscisse de l'Image
		@param _dimY la dimension en ordonné de l'Image
		*/
        void changerDimension(int _dimX, int _dimY);

		/**
		@brief Changer l'angle de rotation de l'Image
		@param _angle L'angle de l'image (en degrée)
		*/
        void changerAngle(double _angle);

		/**
   		@brief Accesseur de position X
   		@return x
   		*/
        int getX() const;
        
        /**
   		@brief Accesseur de position Y
   		@return y
   		*/
        int getY() const;
        
        /**
   		@brief Accesseur de dimension X
   		@return dimX
   		*/
        int getdimX() const;
        
        /**
   		@brief Accesseur de dimension Y
   		@return dimY
   		*/
        int getdimY() const;
        
        /**
   		@brief Accesseur de position sous forme de Vec2
   		@return Un vecteur (x,y)
   		*/
        Vec2 getVec() const;
        
         /**
   		@brief Accesseur d'angle
   		@return angle
   		*/
        double getAngle() const;

		/**
   		@brief Mutateur de position en X
   		@param _x la position en abscisse de l'Image
   		*/
        void setX(int _x);
        
        /**
   		@brief Mutateur de position en Y
   		@param _y la position en ordonnée de l'Image
   		*/
        void setY(int _y);
        
        /**
   		@brief Mutateur d'angle de rotation
   		@param _angle L'angle (en degrées) de l'Image
   		*/
        void setAngle(double _angle);

		/**
		@brief Afficher l'Image dans la fenetre
		*/
		void afficher();

		/**
		@brief Afficher l'Image dans la fenetre avec une position définie à l'exterieur
		@param _rect Le SDL_Rect ou afficher l'Image
		*/
		void afficher(SDL_Rect * _rect);

		/**
		@brief Afficher l'Image dans la fenetre avec une position et un angle définies à l'exterieur
		@param _rect Le SDL_Rect ou afficher l'Image
		@param _angle L'angle (en degrées) de l'Image
		*/
		void afficherExp(SDL_Rect * _rect, double _angle);
};

#endif
