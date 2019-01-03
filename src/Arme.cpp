#include "Arme.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Arme::Arme()
{
  	nom = "default";
  	degat = 1;
  	vitesse = 0.0;
}

Arme::Arme(string _nom, int _degat, int _munitionMax, int _munition, int _tailleChargeur, double _tempsRechargement, double _vitesse)
{
	nom = _nom;
	degat = _degat;
	munitionMax = _munitionMax;
	munition = _munition;
	tailleChargeur = _tailleChargeur;
	munitionChargeur = _tailleChargeur;
	tempsRechargement = _tempsRechargement;
	vitesse = _vitesse;
}

void Arme::recharger()
{
	int diff;
	if (munition < tailleChargeur)
	{
		munitionChargeur = munition;
		munition = 0;
	}
		else
	{
		diff = tailleChargeur-munitionChargeur;
		munitionChargeur +=diff;
		munition-=diff;
	}
}

Arme::~Arme(){

}

void Arme::setNom(string _nom)
{
	nom = _nom;
}

void Arme::setDegat(int _degat)
{
	degat = _degat;
}

void Arme::setMunitionMax(int _munitionMax)
{
  	munitionMax = _munitionMax;
}

void Arme::setMunition(int _munition)
{
  	munition = _munition;
}


void Arme::setTailleChargeur(int _tailleChargeur)
{
  	tailleChargeur = _tailleChargeur;
}

void Arme::setMunitionChargeur(int _munitionChargeur)
{
  	munitionChargeur = _munitionChargeur;
}

void Arme::setTempsRechargement(double _tempsRechargement)
{
  	tempsRechargement = _tempsRechargement;
}

void Arme::setVitesse(double _vitesse)
{
  	vitesse = _vitesse;
}

string Arme::getNom()const
{
  	return nom;
}

int Arme::getDegat()const
{
  return degat;
}

int Arme::getMunitionMax()const
{
  	return munitionMax;
}

int Arme::getMunition()const
{
  	return munition;
}

int Arme::getTailleChargeur()const
{
  	return tailleChargeur;
}

int Arme::getMunitionChargeur()const
{
  	return munitionChargeur;
}

double Arme::getTempsRechargement()const
{
  	return tempsRechargement;
}

double Arme::getVitesse()const
{
  	return vitesse;
}

void Arme::tirer() 
{
  	munitionChargeur -= 1;
}

void Arme::chargerArme(string chemin)
{
	ifstream fichier;
	fichier.open(chemin.c_str());

	if(!fichier.is_open())
	{
		cout << "Erreur de chargement de l'arme" << endl;
		exit(1);
	}

	fichier >> nom >> degat >> munitionMax >> tailleChargeur >> tempsRechargement >> vitesse;
	munition = munitionMax;
	munitionChargeur = tailleChargeur;

	fichier.close();
}
