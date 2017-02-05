#include"UMinusNode.h"

double UMinusNode::Calc()const
{
	std::cout << "UMinus" << std::endl;
	return -(_pNode->Calc());
}