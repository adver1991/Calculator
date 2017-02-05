#ifndef STRINGBUFFER_H
#define STRINGBUFFER_H
#include<cctype>
#include<cstring>
class StringBuffer
{
public:
	StringBuffer(int size) :_curOffset(0),maxBufSize(size)
	{
		_buf = new char[size];
	}
	~StringBuffer()
	{
		delete[]_buf;
	}
	bool WillFit(int len)const
	{
		return _curOffset + len + 1 < maxBufSize;
	}
	void Add(char const * str)
	{
		std::strcpy(&_buf[_curOffset], str);
		//strlen()计算长度不包含'\0'
		_curOffset += std::strlen(str) + 1;
	}
	int GetOffset()const
	{
		return _curOffset;
	}
	bool IsEqual(int offStr, char const * str)const
	{
		char const * strStored = &_buf[offStr];
		//字符串相同时，strcmp返回0
		return std::strcmp(str, strStored)==0;
	}
	char const * GetString(int offStr)const
	{
		return &_buf[offStr];
	}
private:
	char * _buf;
	const int maxBufSize;
	int _curOffset;
};

#endif