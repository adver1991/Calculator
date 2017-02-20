#ifndef HTABLE_H
#define HTABLE_H
#include "List.h"
#include<cassert>
class HTable
{
public:
	friend class IdSeq;
	explicit HTable(int size) :_size(size)
	{
		_aList = new List[size];
	}
	~HTable()
	{
		delete[] _aList;
	}
	void Add(char const * str, int id);
private:
	List & Find(char const * str)const;
	int hash(char const * str)const;
	List* _aList;
	int const _size;
};

class IdSeq :public ListSeq
{
public:
	IdSeq(HTable const & htab, char const* str)
		:ListSeq(htab.Find(str)){};
};
#endif