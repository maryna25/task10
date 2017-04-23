#pragma once
#include "Expresion.h"
#include <iostream>
class Plus:public Expresion {
private:
    Expresion *left, *right;
public:
    Plus(Expresion *l, Expresion *r) : left(l), right(r) { }
    
    double evaulate() 
	{
        return left->evaulate() + right->evaulate();
    }
};
