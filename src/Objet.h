#ifndef OBJET_H
#define OBJET_H

#include<iostream>
#include "Vec2.h"
#include "Cercle.h"

/**
@class Objet
@brief Un objet ramassable par le jouer
*/
class Objet
{
	private:
		int id;
		Cercle collision;

	public:
		
		/**
		@brief Constructeur d'Objet (sans paramètres)
		*/
		Objet();
		
		/**
		@brief Constructeur d'Objet
		@param _id L'identifiant de l'Objet
		@param x La position en X de l'Objet
		@param y La position en Y de l'Objet
		*/
		Objet(int _id, int x, int y);
		
		/**
		@brief Constructeur d'Objet
		@param _id L'identifiant de l'Objet
		@param pos La position (x,y) de l'Objet
		*/
		Objet(int _id, Vec2 pos);
		
		/**
		@brief Constructeur d'Objet
		@param _id L'identifiant de l'Objet
		@param pos La boite de collision de l'Objet
		*/
		Objet(int _id, Cercle pos);
		
		/**
		@brief Destructeur d'objet
		*/
		~Objet();
		
		/**
		@brief Obtenir la position de l'Objet sous forme de Vec2
		@return Un vecteur (x,y) de la position de l'Objet
		*/
		Vec2 getPosition() const;
		
		/**
		@brief Obtenir le rayon de l'Objet
		@return rayon
		*/
		double getRayon() const;
		
		/**
		@brief Obtenir l'identifiant de l'Objet
		@return id
		*/
		int getId() const;

};

#endif
