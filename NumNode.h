#ifndef NUMNODE_H
#define NUMNODE_H
#include "Node.h"
class NumNode :public Node
{
public:
	NumNode(double num) :_num(num){}
	double Calc()const;
private:
	const double _num;
};
#endif