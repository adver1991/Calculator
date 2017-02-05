#include"VarNode.h"
#include"Store.h"
double VarNode::Calc()const
{
	double x = 0.0;
	if (_store.IsInit(_id))
		x = _store.Value(_id);
	else
		std::cout << "Use of uninitialized variable\n";
	return x;
}
void VarNode::Assign(double val)
{
	_store.SetValue(_id, val);
}
//¸²¸ÇÐéº¯Êý
bool VarNode::IsLvalue()const
{
	return true;
}