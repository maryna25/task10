#pragma once
#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include "Minus.h"
#include "Expresion.h"
#include "Constant.h"
#include "Plus.h"
#include "Product.h"
#include "Division.h"

using namespace std;
class Parser 
{
	private:
		string expr;
	
	public:
		Parser(string str) 
		{
			expr = str;
		}
		
		virtual ~Parser() {}
		
		double calculate() 
		{
			stack<char> operands;
			stack<Expresion*> vals;
			for (int i = 0; i < expr.size(); i++)
			{
				if (i == 0 && expr[i] == '-')
				{
					vals.push(new Constant(0));
					operands.push(expr[i]);
				}
				else if (expr[i] == '(')
				{
					if (expr[i+1] == '-') 
						vals.push(new Constant(0));
				}
				else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
				{
					operands.push(expr[i]);
				}
				else if (expr[i] == ')')
				{
					make_operation(operands, vals);
				} 
				
				else 
				{
					string num;
					while (expr[i] >= '0' && expr[i] <= '9')
					{
						num += expr[i];
						i++;
					}
					i--;
					vals.push(new Constant(stod(num)));
					vals.top()->evaulate();
				}
			}
			return vals.top()->evaulate();
		}
		double make_operation(stack<char> &operands, stack<Expresion*> &vals)
		{
			char op = operands.top();
			operands.pop();
			Expresion *element = vals.top();
			vals.pop();
			Expresion  *res = nullptr;
			if (op == '-')
			{
				res = new Minus(vals.top(), element);
			}
			else if (op == '+')
			{
				res = new Plus(vals.top(), element);
			}
			else if (op == '/')
			{
				res = new Division(vals.top(), element);
			}
			else if (op == '*')
			{
				res = new Product(vals.top(), element);
			}
			vals.pop();
			vals.push(new Constant(res->evaulate()));
			return vals.top()->evaulate();
		}
};
