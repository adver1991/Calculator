#ifndef ISTACK_H
#define ISTACK_H
#include <cassert>
#include <iostream>
const int initStack = 1;
class IStack
{
public:
	IStack();
	~IStack();
	void Push(int i);
	int Pop();
	int Top()const;
	bool IsEmpty()const;
private:
	void Grow();
	int *_arr;
	int _capacity;
	int _top;
};

#endif