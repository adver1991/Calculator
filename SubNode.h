#ifndef SUBNODE_H
#define SUBNODE_H
#include "BinNode.h"
class SubNode :public BinNode
{
public:
	SubNode(Node* pLeft, Node *pRight)
		:BinNode(pLeft, pRight){}
	double Calc()const;

};
#endif