#ifndef MULTNODE_H
#define MULTNODE_H
#include"BinNode.h"
class MultNode:public BinNode
{
public:
	MultNode(Node* pLeft, Node* pRight)
		:BinNode(pLeft, pRight){}
	double Calc()const;

};

#endif