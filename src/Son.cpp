#include "Son.h"

#include<iostream>

using namespace std;

Son::Son()
{
	channel = -2;
}

Son::Son(string _chemin)
{
	chemin = _chemin;

	fichier = Mix_LoadWAV(chemin.c_str());
	channel = -2;

	if(!fichier)
	{
		cout << "Erreur pour charger son : " << chemin << endl;
	}
}

Son::~Son()
{
	if(fichier)
	{
		Mix_FreeChunk(fichier);
	}
}

bool Son::enCours() const
{
	int i = Mix_Playing(channel);

	return (i == 1);
}

void Son::charger(string _chemin)
{
	chemin = _chemin;
	
	if(enCours())
	{
		Mix_FreeChunk(fichier);
	}
	
	fichier = Mix_LoadWAV(chemin.c_str());
	channel = -2;

	if(!fichier)
	{
		cout << "Erreur pour charger son : " << chemin << endl;
	}
}

void Son::jouer()
{
	if(fichier)
	{
		channel = Mix_PlayChannel(-1, fichier , 0);
	}
	else
	{
		cout << "Erreur : Aucun son chargée " << endl;
	}
}

void Son::pause()
{
	if(enCours())
	{
		Mix_Pause(channel);
	}
}
