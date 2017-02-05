#include"AssignNode.h"
double AssignNode::Calc()const
{
	double x = _pRight->Calc();
	_pLeft->Assign(x);
	return x;
}
