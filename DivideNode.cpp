#include"DivideNode.h"

double DivideNode::Calc()const
{
	std::cout << "Dividing" << std::endl;
	if (_pRight->Calc() == 0)
	{
		return HUGE_VAL;
	}
	return _pLeft->Calc() / _pRight->Calc();
}