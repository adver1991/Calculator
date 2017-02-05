#include"IStack.h"

IStack::IStack() :_top(0), _capacity(initStack)
{
	_arr = new int[initStack]; //分配内存
}
IStack::~IStack()
{
	delete [] _arr; //释放内存
}
void IStack::Push(int i)
{
	assert(_top <= _capacity);
	if (_top == _capacity)
	{
		Grow();
	}
	_arr[_top] = i;
	++_top;
}
void IStack::Grow()
{
	std::cout << "Doubling stack from " << _capacity << ".\n";
	//分配新数组
	int *arrNew = new int[2 * _capacity];
	//复制所有数据项
	for (int i = 0; i < _capacity; ++i)
	{
		arrNew[i] = _arr[i];
	}
	_capacity *= 2;
	//释放就内存
	delete[]_arr;
	_arr = arrNew;
}
int IStack::Pop()
{
	assert(_top > 0);
	--_top;
	return _arr[_top];
}
int IStack::Top()const
{
	assert(_top > 0);
	return _arr[_top - 1];
}
bool IStack::IsEmpty()const
{
	assert(_top >= 0);
	return _top == 0;
}