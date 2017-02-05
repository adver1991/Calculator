#ifndef ADDNODE_H
#define ADDNODE_H
#include "BinNode.h"
class AddNode:public BinNode
{
public:
	AddNode(Node* pLeft, Node *pRight) 
		:BinNode(pLeft, pRight){}
	double Calc()const;

};
#endif