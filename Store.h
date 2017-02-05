#ifndef STORE_H
#define STORE_H
#include<cassert>
class SymbolTable;//forward declaration
enum {stNotInit,stInit};
class Store
{
public:
	Store(int size, SymbolTable& symTab);
	~Store()
	{
		delete[]_cell;
		delete[]_status;
	}
	bool IsInit(int id)const
	{
		return(id < _size && _status[id] != stNotInit);
	}
	double Value(int id)const
	{
		assert(IsInit(id));
		return _cell[id];
	}
	void SetValue(int id, double val)
	{
		if (id < _size)
		{
			_cell[id] = val;
			_status[id] = stInit;
		}
	}
private:
	//�����С
	int _size;
	//��Ԫ����
	double* _cell;
	//״̬����
	unsigned char* _status;
};

#endif