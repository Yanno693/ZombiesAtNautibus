#ifndef HUMANOIDE_H
#define HUMANOIDE_H

#include<iostream>
#include "Vec2.h"
#include "Rectangle.h"
#include "Cercle.h"

/**
@class Humanoide
@brief Une humanoide capable de se mouvoir et de mourir
*/
class Humanoide
{
	protected:
		int hp;
		Vec2 position;
		Vec2 vitesse;
		Vec2 acceleration;
		Cercle collision;
		bool vivant;

	public:

                /**
                 * @brief Constructeur de Humanoide (sans paramètres)
                 */
		Humanoide();

                /**
                 * @brief Destructeur de Humanoide
                 */
		~Humanoide();

                /**
                 * @brief Mutateur de hp
                 * @param  _hp nouvelle valeur de hp
                 */
		void setHp(int _hp);

                /**
                 * @brief Mutateur de position
                 * @param _position nouvelle valeur de position
                 */
		void setPosition(Vec2 _position);

                /**
                 * @brief Mutateur de vitesse
                 * @param _vitesse nouvelle valeur de position
                 */
		void setVitesse(Vec2 _vitesse);

                /**
                 * @brief Mutateur d'acceleration
                 * @param _acceleration nouvelle valeur d'acceleration
                 */
		void setAcceleration(Vec2 _acceleration);

				/**
                 * @brief Mutateur de boite de collision
                 * @param _collision nouvelle valeur de la boite de collision
                 */
		void setCollision(Cercle _collision);

                /**
                 * @brief Accesseur de hp
                 * @return hp
                 */
		int getHp()const;

                /**
                 * @brief Accesseur de position
                 * @return position
                 */
		Vec2 getPosition()const;

                /**
                 * @brief Accesseur de vitesse
                 * @return vitesse
                 */
		Vec2 getVitesse()const;

                /**
                 * @brief Accesseur d'acceleration
                 * @return d'acceleration
                 */
		Vec2 getAcceleration()const;

		/**
                 * @brief Accesseur de boite de collision
                 * @return de boite de collision
                 */
		Cercle getCollision()const;
		void prendreDegat(int degat);
		void toucheBarriere()const;

		bool estVivant()const;


};

#endif
