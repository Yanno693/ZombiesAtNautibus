#ifndef BOUTON_H
#define BOUTON_H

#include <iostream>
#include <string>
#include "Vec2.h"
#include "Rectangle.h"
#include "Image.h"

/**
@class Bouton
@brief Un bouton interactif qui change quand le joueur passe la souris dessus
*/
class Bouton 
{
	private:
		
		Rectangle position;
		Image normal;
		Image focus;
		SDL_Rect * rect;
		SDL_Renderer * renderer;
		

	public:
		/**
	   	@brief Constructeur de Bouton
	   	@param _c1 Le coin haut-gauche du Bouton
	   	@param _c2 Le coin bas-droit du Bouton
	   	@param _normal Le chemin de l'Image à afficher en temps normal
	   	@param _focus Le chemain de l'Image à affichier quand on passe la souris dessus
	   	@param _renderer le SDL_Renderer a relier au Bouton
	   	*/
		Bouton(Vec2 _c1, Vec2 _c2, string _normal, string _focus, SDL_Renderer * _renderer);
		
		/**
	   	@brief Constructeur de Bouton
	   	@param _position Le Rectangle deffinissant la zone d'affichage du Bouton
	   	@param _normal Le chemin de l'Image à afficher en temps normal
	   	@param _focus Le chemain de l'Image à affichier quand on passe la souris dessus
	   	@param _renderer le SDL_Renderer a relier au Bouton
	   	*/
		Bouton(Rectangle _position, string _normal, string _focus, SDL_Renderer * _renderer);
		
		/**
		@brief Destructeur de Bouton
		*/
		~Bouton();
		
		/**
		@brief Teste si le Bouton est survolé ou pas
		@param curseur La position du curseur
		*/
		bool estFocus(Vec2 curseur);
		
		/**
		@brief Affiche le Bouton dans la fenetre
		@param curseur La position du curseur
		*/
		void afficher(Vec2 curseur);

};

#endif
