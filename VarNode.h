#ifndef VARNODE_H
#define VARNODE_H
#include"Node.h"
class Store;

class VarNode :public Node
{
public:
	VarNode(int id, Store& store) :_id(id), _store(store){}
	double Calc()const;
	bool IsLvalue()const;
	void Assign(double val);
private:
	int const _id;
	Store& _store;
};
#endif