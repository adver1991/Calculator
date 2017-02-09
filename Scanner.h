#ifndef SCANNER_H
#define SCANNER_H
#include<iostream>
#include<cassert>
#include<cctype>
const int maxSymLen = 10;
enum EToken
{
	tEnd,
	tError,
	tNumber,// 字面值数字
	tPlus,// +
	tMult,// *
	tMinus,// -
	tDivide,// /
	tLParen,// (
	tRParen,// )
	tAssign,// =
	tIdent //标识符
};
//扫描器
class Scanner
{
public:
	Scanner(char const * buf);
	//返回记号
	EToken Token()const{ return _token; }
	bool IsDone()const;
	void Accept();
	double Number()
	{
		assert(_token == tNumber);
		return _number;
	}
	void GetSymbolName(char * strOut, int & len);
	bool IsEmpty() const;
private:
	//忽略空格
	void EatWhite();
	char const * const _buf;
	EToken _token;
	double _number;
	int _iLook;
	int _lenSymbol;//当前识别标识符的长度
	int _iSymbol;//标识符的开始
};
#endif