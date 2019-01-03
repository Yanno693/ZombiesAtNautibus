#ifndef MUSIQUE_H
#define MUSIQUE_H

#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<string.h>

using namespace std;

/**
@class Musique
@brief Une musique a jouer en jeu
*/
class Musique
{
	private:
		string chemin;
		Mix_Music* fichier;

	public:

		/**
		@brief Constructeur de Musique (sans paramètres)
		*/
		Musique();

		/**
		@brief Constructeur de Musique
		@param _chemin Le chemin du fichier à charger (de préférence un .ogg)
		*/
		Musique(string _chemin);

		/**
		@brief Destructeur de Musique
		*/
		~Musique();
		
		/**
		@brief Charger un fichier sonore à jouer
		@param _chemin Le chemin du fichier à charger (de préférence un .ogg)
		*/
		void charger(string _chemin);

		/**
		@brief Joueur le morceau chargé
		*/
		void jouer();

		/**
		@brief Mettre le morceau en pause
		*/
		void pause();

		/**
		@brief Continuer le morceau
		*/
		void reprendre();
		
		/**
		@brief savoir si le morceau est joué ou pas
		@return un booléen vrai si le morceau est en train d'être joué
		*/
		bool enCours() const;
};

#endif
