#include"Htable.h"
List const & HTable::Find(char const * str)const
{
	int i = hash(str);
	return _aList[i];
}
void HTable::Add(char const * str, int id)
{
	int i = hash(str);
	_aList[i].Add(id);
}
int HTable::hash(char const * str)const
{
	assert(str != 0 && str[0] != 0);
	unsigned h = str[0];
	for (int i = 1; str[i] != 0; ++i)
		h = (h << 4) + str[i];
	return h % _size;
}
