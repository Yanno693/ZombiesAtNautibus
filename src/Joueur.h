#ifndef JOUEUR_H
#define JOUEUR_H

#include<iostream>
#include "Vec2.h"
#include "Rectangle.h"
#include "Cercle.h"
#include "Humanoide.h"
#include "Arme.h"
#include "Zombie.h"


/**
@class Joueur
@brief Un joueur equipé d'une arme
*/
class Joueur : public Humanoide
{
	private:
		Arme arme;

	public:

		/**
		@brief Constructeur de Joueur (sans paramètres)
		*/
		Joueur();
		
		/**
		@brief Mutateur d'Arme du Joueur
		@param _arme l'Arme à attribuer au joueur
		*/
		void setArme(Arme _arme);
		
		/**
		@brief Accesseur d'Arme du Joueur
		@return arme
		*/
		Arme getArme();
		
		/**
		@brief Teste si le Joueur touche un Zombie
		@param Z un Zombie
		@return Un booléen vrai si le Joueur touche le Zombie
		*/
		bool toucheZombie(Zombie & Z);

		/**
		@brief Destructeur de joueur
		*/
		~Joueur();
		
		/**
		@brief Teste si le Joueur touche le bord du terrain
		@param Xmin limite à gauche
		@param Xmax limite à droite
		@param Ymin limite en haut
		@param Ymax limite en bas
		*/
		void toucheBord(double Xmin, double Xmax, double Ymin, double Ymax);
};

std::ostream& operator<< (std::ostream& flux, Joueur& joueur);

#endif
