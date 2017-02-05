#include"SubNode.h"

double SubNode::Calc()const
{
	std::cout << "Subing" << std::endl;
	return _pLeft->Calc() - _pRight->Calc();
}