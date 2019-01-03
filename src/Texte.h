#ifndef TEXTE_H
#define TEXTE_H

#include<iostream>
#include<string.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<string.h>
using namespace std;

/**
@class Texte
@brief Un texte modifiable et affichage dans la fenetre
*/
class Texte
{
	private:
	  string cheminPolice;
	  string texte;

	  TTF_Font * police;
	  SDL_Color * couleur;
	  SDL_Renderer * renderer;
	  SDL_Surface * surface;
	  SDL_Texture * texture;
	  SDL_Rect * rect;

	  int x;
	  int y;
	  int dimX;
	  int dimY;



	public:
	
		/**
		@brief Constructeur de Texte (sans paramètres)
		*/
	  	Texte ();
	  	
	  	/**
		@brief Destructeur de Texte
		*/
	  	~Texte();
	  	
	  	/**
		@brief Constructeur de Texte
		@param cheminPolice Le chemin de la police de caractere a utiliser (au format .ttf)
		@param _texte Le contenu du Texte a afficher
		@param _renderer Le SDL_Renderer a relié au Texte
		*/
	  	Texte (string cheminPolice, string _texte, SDL_Renderer * _renderer);
	  	
	  	/**
	  	@brief Modifier le contenu du Texte a afficher
	  	@param _texte Le contenu du Texte a afficher
	  	*/
	  	void setTexte(string _texte);
	  	
	  	/**
	  	@brief Modifier la couleur du Texte a afficher
	  	@param _r la composante rouge de la couleur du Texte
	  	@param _g la composante verte de la couleur du Texte
	  	@param _b la composante bleue de la couleur du Texte
	  	*/
	  	void setCouleur (unsigned int _r, unsigned int _g, unsigned int _b);
	  	
	  	/**
		@brief Changer la position du Texte
		@param _x la position en abscisse du Texte
		@param _y la position en ordonné du Texte
		*/
	  	void setPosition(int _x,int _y);
	  	
	  	/**
		@brief Changer la dimension du Texte
		@param _dimX la dimension en abscisse du Texte
		@param _dimY la dimension en ordonné du Texte
		*/
	  	void setDimension(int _dimX,int _dimY);
	  	
	  	/**
		@brief Afficher le Texte dans la fenetre
		*/
		void afficher();
		
		/**
		@brief Afficher le Texte dans la fenetre avec une position définie à l'exterieur
		@param _rect Le SDL_Rect ou afficher le Texte
		*/
		void afficher(SDL_Rect * _rect);
};

#endif
