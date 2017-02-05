#include"MultNode.h"
double MultNode::Calc()const
{
	std::cout << "Multiplying" << std::endl;
	return _pLeft->Calc()*_pRight->Calc();
}