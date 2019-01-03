#ifndef SON_H
#define SON_H

#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<string.h>

using namespace std;

/**
@class Son
@brief Un son jouable rapidement en jeu
*/
class Son
{
	private:
		string chemin;
		Mix_Chunk* fichier;
		int channel;
		
	public:

		/**
		@brief Constructeur de Son (sans paramètres)
		*/
		Son();
		
		/**
		@brief Constructeur de Son
		@param _chemin Le chemin du fichier à charger (un .wav)
		*/
		Son(string _chemin);
		
		/**
		@brief Destructeur de Son
		*/
		~Son();
		
		/**
		@brief Charger un fichier sonore à jouer
		@param _chemin Le chemin du fichier à charger (un .wav)
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
		@brief savoir si le morceau est joué ou pas
		@return un booléen vrai si le morceau est en train d'être joué
		*/
		bool enCours()const;

};

#endif
