#include"Store.h"
#include"SymbolTable.h"
#include<iostream>
Store::Store(int size, SymbolTable& symTab) :_size(size)
{
	_cell = new double[size];
	_status = new unsigned char[size];
	for (int i = 0; i < size; ++i)
	{
		_status[i] = stNotInit;
	}
	//add predefined constants
	std::cout << "e= " << std::exp(1) << std::endl;
	int id = symTab.ForcAdd("e");
	SetValue(id, std::exp(1));
	std::cout << "pi= " << 2 * std::acos(0.0)//acos·´ÓàÏÒ 
		<< std::endl;
	id = symTab.ForcAdd("pi");
	SetValue(id, 2.0*std::acos(0.0));
}