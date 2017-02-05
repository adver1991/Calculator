#ifndef HTABLE_H
#define HTABLE_H
#include "List.h"
#include<cassert>
class HTable
{
public:
	explicit HTable(int size) :_size(size)
	{
		_aList = new List[size];
	}
	~HTable()
	{
		delete[] _aList;
	}
	List const & Find(char const * str)const;
	void Add(char const * str, int id);
private:
	int hash(char const * str)const;
	List* _aList;
	int const _size;
};
#endif