#pragma once

#include <stdio.h>
#include "Expresion.h"
#include <iostream>

class Constant : public  Expresion
{
	private:
		double value;
	
	public:
		Constant(double w) : value(w){}
		double evaulate() 
		{
			return value;
		}
};
