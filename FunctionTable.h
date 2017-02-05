#ifndef FUNCTIONTABLE_H
#define FUNCTIONTABLE_H
class SymbolTable;//Ç°ÏòÉùÃ÷
typedef  double(*PtrFun)(double);
int const maxIdFun = 15;
class FunctionEntry
{
public:
	PtrFun pFun;
	char* strFun;
};
 extern FunctionEntry funArr[];
class FunctionTable
{
public:
	FunctionTable(SymbolTable& symTab, FunctionEntry funArr[]);
	int Size()const{ return _size; }
	PtrFun GetFun(int id)const{ return _pFun[id]; }
private:
	PtrFun _pFun[maxIdFun];
	int _size;
	
};
#endif