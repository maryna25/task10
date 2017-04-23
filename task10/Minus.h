#pragma once
#include "Expresion.h"
#include <iostream>

class Minus : public Expresion 
{
	private:
		Expresion *left,*right;
	
	public:
		Minus(Expresion *l, Expresion *r) : left(l), right(r){}
		double evaulate() 
		{
			return left->evaulate() - right->evaulate();
		}
};
