#ifndef ARME_H
#define ARME_H

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


/**
@class Arme
@brief Une arme utilisable par le joueur
*/
class Arme
{
private:
  string nom;
  int degat;

  int munitionMax;
  int munition;

  int tailleChargeur;
  int munitionChargeur;
  double tempsRechargement;
  double vitesse;


public:

  /**
   * @brief Constructeur d'Arme (sans paramètres)
   */
  Arme();

  /**
   * @brief Constructeur d'Arme
   * @param _nom nom de l'Arme
   * @param _degat degats infligés par l'Arme
   * @param _munitionMax nombre maximale de munitions de l'Arme
   * @param _munition munitions courrantes de l'arme
   * @param _tailleChargeur nombre de munitions maximale dans le chargeur
   * @param _tempsRechargement temps mis par le joueur pour recharger
   * @param _vitesse cadence de tir
   */
  Arme(string _nom, int _degat, int _munitionMax, int _munition, int _tailleChargeur, double _tempsRechargement, double _vitesse);

  /**
   * @brief Mutateur de nom
   * @param _nom nouveau nom
   */
  void setNom(string _nom);

  /**
   * @brief Mutateur de degat
   * @param _degat valeur de degat
   */
  void setDegat(int _degat);

	/**
   * @brief Mutateur de munition maximales
   * @param _munitionMax valeur des munitions maximales
   */
  void setMunitionMax(int _munitionMax);

  /**
   * @brief Mutateur de munition
   * @param _munition valeur des munitions
   */
  void setMunition(int _munition);

  /**
   * @brief Mutateur de chargeur
   * @param _tailleChargeur nouvelle taille du chargeur
   */
  void setTailleChargeur(int _tailleChargeur);

	/**
   * @brief Mutateur de munition du chargeur
   * @param _munitionChargeur valeur des munitions du chargeur
   */
  void setMunitionChargeur(int _munitionChargeur);

  /**
   * @brief Mutateur de tempsRechargement
   * @param _tempsRechargement nouveau temps de rechargement
   */
  void setTempsRechargement(double _tempsRechargement);

  /**
   * @brief Mutateur de setVitesse
   * @param _vitesse nouvelle vitesse des balles
   */
  void setVitesse(double _vitesse);

  /**
   * @brief Accesseur de nom
   * @return nom
   */
  string getNom()const;

  /**
   * @brief Accesseur de degat
   * @return degat
   */
  int getDegat()const;

	/**
   * @brief Accesseur de munition maximales
   * @return munition
   */
  int getMunitionMax()const;

  /**
   * @brief Accesseur de munition
   * @return munition
   */
  int getMunition()const;


  /**
   * @brief Accesseur de tailleChargeur
   * @return tailleChargeur
   */
  int getTailleChargeur()const;

  /**
   * @brief Accesseur de tempsRechargement
   * @return tempsRechargement
   */
  double getTempsRechargement()const;

  /**
   * @brief Accesseur de vitesse
   * @return vitesse
   */
  double getVitesse()const;

  /**
   * @brief Accesseur de munitionChargeur
   * @return munitionChargeur
   */
  int getMunitionChargeur()const;

  void chargerArme(string chemin);

   /**
    * @brief Destructeur d'Arme
    */
    ~Arme();

    void recharger();

    /**
     * @brief décremente munitionChargeur de 1;
     */
    void tirer();

};

#endif
