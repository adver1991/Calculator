#include"SymbolTable.h"
SymbolTable::SymbolTable(int size)
	:_curId(0), 
	_maxId(size), 
	_htab(size + 1),
	_strBuf(size*10)
{
	_offStr = new int[size];
}
SymbolTable::~SymbolTable()
{
	delete[]_offStr;
}

int SymbolTable::ForcAdd(char const * str)
{
	int len = std::strlen(str);
	if (_curId == maxStrings || !_strBuf.WillFit(len))
	{
		return idNotFound;
	}
	//_curid是 字符串对应的ID。如"one"对应ID1。而字符串缓冲器（数组）中字符串的起始索引
	//是_offStr[curID]的值，非curID的值。
	_offStr[_curId] = _strBuf.GetOffset();
	_strBuf.Add(str);
	_htab.Add(str, _curId);
	++_curId;
	return _curId - 1;
}
int SymbolTable::Find(char const * str)const
{
	for (IdSeq seq(_htab, str);
		!seq.AtEnd();
		seq.Advance())
	{
		int id = seq.GetId();
		int offStr = _offStr[id];
		if (_strBuf.IsEqual(offStr, str))
			return id;
	}
	return idNotFound;
}
char const * SymbolTable::GetString(int id)const
{
	assert(id >= 0);
	assert(id < _curId);
	//获得字符串缓冲器中的索引
	int offStr = _offStr[id];
	return _strBuf.GetString(offStr);
}