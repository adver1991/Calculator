#ifndef DIVIDENODE_H
#define DIVIDENODE_H
#include "BinNode.h"
class DivideNode:public BinNode
{
public:
	DivideNode(Node* pLeft, Node *pRight)
		:BinNode(pLeft, pRight){}
	double Calc()const;

};
#endif