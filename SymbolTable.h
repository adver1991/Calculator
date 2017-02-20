#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "Htable.h"
#include "StringBuffer.h"
int const idNotFound = -1;
int const maxStrings = 100;
//·ûºÅ±íÀà
class SymbolTable
{
public:
	explicit SymbolTable(int size);
	~SymbolTable();
	int ForcAdd(char const * str);
	int Find(char const * str)const;
	char const * GetString(int id)const;
private:
	HTable _htab;//¹þÏ£±í
	int _maxId;
	int* _offStr;
	int _curId;
	StringBuffer _strBuf;
};

#endif