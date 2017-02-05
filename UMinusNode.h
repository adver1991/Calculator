#ifndef UMINUSNODE_H
#define UMINUSNODE_H
#include"Node.h"
class UMinusNode :public Node
{
public:
	UMinusNode(Node* pNode)
		:_pNode(pNode){}
	~UMinusNode(){ delete _pNode; }
	double Calc()const;
private:
	Node* _pNode;
};
#endif