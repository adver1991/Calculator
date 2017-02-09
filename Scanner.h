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
	tNumber,// ����ֵ����
	tPlus,// +
	tMult,// *
	tMinus,// -
	tDivide,// /
	tLParen,// (
	tRParen,// )
	tAssign,// =
	tIdent //��ʶ��
};
//ɨ����
class Scanner
{
public:
	Scanner(char const * buf);
	//���ؼǺ�
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
	//���Կո�
	void EatWhite();
	char const * const _buf;
	EToken _token;
	double _number;
	int _iLook;
	int _lenSymbol;//��ǰʶ���ʶ���ĳ���
	int _iSymbol;//��ʶ���Ŀ�ʼ
};
#endif