#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H
#include"BinNode.h"
class AssignNode :public BinNode
{
public:
	AssignNode(Node* pLeft, Node* pRight)
		:BinNode(pLeft, pRight)
	{
		assert(pLeft->IsLvalue());
	}
	double Calc()const;
};
#endif