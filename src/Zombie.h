#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include "Vec2.h"
#include "Cercle.h"
#include "Humanoide.h"

/**
@class Zombie
@brief Un zombie se deplacant et blessant sa cible
*/
class Zombie : public Humanoide
{
	private:
		int degat;
		Vec2 cible;

	public:

        /**
        @brief Constructeur de Zombie (sans paramètres)
        */
		Zombie();

        /**
        @brief Constructeur de Zombie
        @param _degat infligés par le Zombie
        @param _cible position vers laquelle il se dirige
        */
		Zombie(int _degat, Vec2 _cible);

        /**
        @brief Mutateur de degat
        @param _degat nouvelle valeur de degat
        */
		void setDegat(int _degat);

        /**
        @brief Mutateur de cible
        @param _cible nouvelle valeur de cible
        */
		void setCible(Vec2 _cible);

        /**
        @brief Accesseur de degat
        @return degat
        */
		int getDegat()const;

        /**
        @brief Accesseur de cible
        @return cible
        */
		Vec2 getCible()const;

        /**
        @brief Destructeur de Zombie
        */
		~Zombie();
};

std::ostream& operator<< (std::ostream& flux, Zombie& zombie);

#endif
