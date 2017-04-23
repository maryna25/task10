#pragma once
#include "Expresion.h"
#include <iostream>

class Product:public Expresion  
{
	private:
		Expresion  *left, *right;
	
	public:
		Product(Expresion  *l, Expresion  *r) : left(l), right(r) {}
		double evaulate() 
		{
			return left->evaulate() * right->evaulate();
		}
};
