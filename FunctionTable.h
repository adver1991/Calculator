#ifndef FUNCTIONTABLE_H
#define FUNCTIONTABLE_H
class SymbolTable;//Ç°ÏòÉùÃ÷
typedef  double(*PtrFun)(double);
class FunctionEntry
{
public:
	PtrFun pFun;
	char* strFun;
};
class FunctionTable
{
public:
	FunctionTable(SymbolTable& symTab);
	int Size()const{ return _size; }
	PtrFun GetFun(int id)const{ return _pFun[id]; }
	~FunctionTable();
private:
	PtrFun* _pFun;
	int _size;
	
};
#endif