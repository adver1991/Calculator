#ifndef NODE_H
#define NODE_H
#include <iostream>
#include<cassert>
class Node
{
public:
	virtual ~Node(){}
	virtual double Calc()const = 0;
	virtual bool IsLvalue()const;
	virtual void Assign(double value){};
};

#endif