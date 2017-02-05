#ifndef FUNNODE_H
#define FUNNODE_H
#include"Node.h"
#include"FunctionTable.h"
class FunNode :public Node
{
public:
	FunNode(PtrFun pFun, Node* pNode)
		:_pNode(pNode), _pFun(pFun)
	{}
	~FunNode(){ delete _pNode; }
	double Calc()const;
private:
	Node* const _pNode;
	PtrFun _pFun;
};

#endif