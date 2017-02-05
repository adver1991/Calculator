#ifndef BINNODE_H
#define BINNODE_H
#include "Node.h"
class BinNode :public Node
{
public:
	BinNode(Node * pLeft, Node * pRight)
		:_pLeft(pLeft), _pRight(pRight){}
	virtual ~BinNode()
	{
		delete _pLeft;
		delete _pRight;
	}
protected:
	Node * const _pLeft;
	Node * const _pRight;
};
#endif