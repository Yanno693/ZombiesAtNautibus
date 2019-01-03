#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "Vec2.h"

/**
@class Cercle
@brief Un cercle defini par son centre et son rayon
*/
class Cercle
{
	private:
		Vec2 centre;
		double rayon;

	public:

                /**
                 * @brief Constructeur de Cercle (sans paramètres)
                 */
		Cercle();

                /**
                 * @brief Constructeur de Cercle
                 * @param _centre position du centre du cercle
                 * @param _rayon rayon du Cercle
                 */
		Cercle(Vec2 _centre,double _rayon);

                /**
                 * @brief Destructeur de Cercle
                 */
		~Cercle();

                /**
                 * @brief Mutateur de Cercle
                 * @param _centre nouvelle position du centre du Cercle
                 * @param _rayon nouveau rayon du Cercle
                 */
		void set(Vec2 _centre, double _rayon);

                /**
                 * @brief Mutateur du centre du Cercle
                 * @param _centre nouvelle position du centre du Cercle
                 */
		void setCentre(Vec2 _centre);

                /**
                 * @brief Mutateur du rayon du Cercle
                 * @param _r nouveau rayon du Cercle
                 */

		void setRayon(double _r);

                /**
                 * @brief Accesseur du centre du Cercle
                 * @return centre
                 */
		Vec2 getCentre()const;

                /**
                 * @brief Accesseur du rayon du Cercle
                 * @return rayon
                 */
		double getRayon()const;

};

std::ostream& operator<< (std::ostream& flux, Cercle& cercle);

#endif
