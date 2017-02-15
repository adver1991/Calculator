#include"FunctionTable.h"
#include"SymbolTable.h"
#include<iostream>
double CoTan(double x);
static FunctionEntry FunctionArray[] =
{
	log, "log",
	log10, "log10",
	exp, "exp",
	sqrt, "sqrt",
	sin, "sin",
	cos, "cos",
	tan, "tan",
	CoTan, "cotan",
	sinh, "sinh",
	cosh, "cosh",
	tanh, "tanh",
	asin, "asin",
	acos, "acos",
	atan, "atan",
};
FunctionTable::FunctionTable(SymbolTable& symTab) 
		:_size(sizeof FunctionArray/sizeof FunctionArray[0])
{
	_pFun = new PtrFun[_size];
	for (int i = 0; i < _size; ++i)
	{
		int len = std::strlen(FunctionArray[i].strFun);
		_pFun[i] = FunctionArray[i].pFun;
		std::cout << FunctionArray[i].strFun << std::endl;
		int j = symTab.ForcAdd(FunctionArray[i].strFun, len);
		assert(i == j);
	}
}
FunctionTable::~FunctionTable()
{
	delete[] _pFun;
}
double CoTan(double x)
{
	double y = tan(x);
	if (y == 0)
	{
		std::cout << "contan of " << x << "undefined" << std::endl;
		return HUGE_VAL;
	}
	return 1.0 / y;
}
