#include "Musique.h"

#include<iostream>

using namespace std;

Musique::Musique()
{

}

Musique::Musique(string _chemin)
{
	chemin = _chemin;
	fichier = Mix_LoadMUS(chemin.c_str());

	if(!fichier)
	{
		cout << "Erreur pour charger musique : " << chemin << endl;
	}
}

Musique::~Musique()
{
	if(fichier)
	{
		Mix_FreeMusic(fichier);
	}
}

bool Musique::enCours()const
{
	int i = Mix_PlayingMusic();

	if(i == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Musique::charger(string _chemin)
{
	if(fichier)
	{
		Mix_FreeMusic(fichier);
	}
	
	chemin = _chemin;
	fichier = Mix_LoadMUS(chemin.c_str());

	if(!fichier)
	{
		cout << "Erreur pour charger musique : " << chemin << endl;
	}
}

void Musique::jouer()
{
	if(fichier)
	{
		Mix_PlayMusic(fichier , -1);
	}
	else
	{
		cout << "Erreur : Aucune musique chargée " << endl;
	}
}

void Musique::pause()
{
	if(enCours())
	{
		Mix_PauseMusic();
	}
}

void Musique::reprendre()
{
	int i = Mix_PausedMusic();

	if(i == 1)
	{
		Mix_ResumeMusic();
	}
	else
	{
		jouer();
	}
}
