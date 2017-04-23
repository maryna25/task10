#pragma once
#include "Expresion.h"
#include <iostream>

class Division : public Expresion 
{
	private:
		Expresion *left, *right;
	
	public:
		Division(Expresion *l, Expresion *r):left(l), right(r) {}
		double evaulate()
		{
			return left->evaulate() / right->evaulate();
		}
};
