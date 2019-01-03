#ifndef VEC2_H
#define VEC2_H

#include<iostream>
#include<math.h>

class Vec2
{
	private:
		double x, y;

	public:

        /**
        @brief Constructeur de Vec2 (sans paramètres)
      	*/
		Vec2();

        /**
        @brief Constructeur de Vec2
        @param _x position abscisse
        @param _y position ordonnée
        */
		Vec2(double _x, double _y);

		/**
		@brief Calcul de l'angle entre 2 vecteurs.
		@param vector Vec2 avec lequel l'angle vas être calculé
		@return double valeur de l'angle en radian
		*/
		double angle(Vec2 vector)const;

        /**
        @brief Destructeur de Vec2
        */
		~Vec2();

        /**
        @brief Mutateur de Vec2
        @param _x nouvelle position abscisse
        @param _y nouvelle position ordonnée
        */
		void set(double _x, double _y);

        /**
        @brief Mutateur de l'abscisse
        @param _x nouvelle position de l'abscisse
        */
		void setX(double _x);

		/**
        @brief Mutateur de l'ordonnée
        @param _y nouvelle position l'ordonnée
        */
		void setY(double _y);

        /**
        @brief Accesseur de l'abscisse
        @return x
        */
		double getX()const;

        /**
        @brief Accesseur de l'ordonnée
        @return y
        */
		double getY()const;

		/**
        @brief Defini un Vec2 comme un nombre complexe
        @param ang L'angle (en radian)
        @param mod Le module
        */
		void setExp(double ang, double mod);

        /**
        @brief surcharge de l'operateur +
        @return vec + v
        */
		Vec2 operator+(Vec2 v);

        /**
        @brief surcharge de l'operateur -
        @return vec - v
        */
		Vec2 operator-(Vec2 v);

        /**
        @brief surcharge de l'operateur *
        @return vec * n
        */
		Vec2 operator*(double n);

        /**
        @brief renvoie le module du vecteur
        */
		double mod() const;

        /**
        @brief renvoie l'angle du vecteur (en radian)
        */
		double arg() const;

        /**
        @brief afiiche les paramètres du vecteur
        */
		void afficher()const;
};

std::ostream& operator<< (std::ostream& flux, Vec2& v);

#endif
