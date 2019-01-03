#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<iostream>
#include "Vec2.h"


/**
@class Rectangle
@brief Un rectangle defini par son coin haut-gauche et son coin bas-droit
*/
class Rectangle
{
	private:
		Vec2 c1, c2;

	public:

		/**
		@brief Construscteur de Rectangle (sans paramètres)
		*/
		Rectangle();

		/**
		@brief Construscteur de Rectangle
		@param _c1 Position du coin haut-gauche
		@param _c2 Position du coin bas-droit
		*/
		Rectangle(Vec2 _c1, Vec2 _c2);

		/**
		@brief Destructeur de Rectangle
		*/
		~Rectangle();

		/**
		@brief Mutateur de Rectangle
		@param _c1 Position du coin haut-gauche
		@param _c2 Position du coin bas-droit
		*/
		void set(Vec2 _c1, Vec2 _c2);

		/**
		@brief Mutateur du coin c1 du Rectangle
		@param _c1 Position du coin haut-gauche
		*/
		void setC1(Vec2 _c1);

		/**
		@brief Mutateur du coin c2 du Rectangle
		@param _c2 Position du coin bas-droit
		*/
		void setC2(Vec2 _c2);

		/**
		@brief Accesseur du coin c1 du Rectangle
		@return c1
		*/
		Vec2 getC1()const;

		/**
		@brief Accesseur du coin c2 du Rectangle
		@return c2
		*/
		Vec2 getC2()const;
		
		/**
		@brief Verifie si on point (x,y) se trouve dans le Rectangle
		@param v Un point (x,y)
		@return Un booléen vrai si le point est dans le Rectangle
		*/
		bool dansRectangle(Vec2 v);

};

std::ostream& operator<< (std::ostream& flux, Rectangle& r);

#endif
