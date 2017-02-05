#include "AddNode.h"

double AddNode::Calc()const
{
	std::cout << "Adding" << std::endl;
	return _pLeft->Calc() + _pRight->Calc();
}