#include"FunNode.h"
#include<cassert>
double FunNode::Calc()const
{
	assert(_pFun != 0);
	return(*_pFun)(_pNode->Calc());
}