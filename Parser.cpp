#include "Parser.h"
#include<iostream>
#include"Store.h"
#include"Node.h"
#include"FunctionTable.h"
#include"SymbolTable.h" 
#include"Scanner.h"
#include"AddNode.h"
#include "AssignNode.h"
#include"SubNode.h"
#include"MultNode.h"
#include"DivideNode.h"
#include"NumNode.h"
#include"FunNode.h"
#include"VarNode.h"
#include"UMinusNode.h"

Parser::~Parser()
{
	delete _pTree;
}       
Parser::Parser(Scanner & scanner,
	Store& store,
	FunctionTable& funTab,
	SymbolTable & symTab)
	:_scanner(scanner),
	_pTree(0),
	_status(stOK),
	_funTab(funTab),
	_store(store),
	_symTab(symTab)
{
	std::cout << "Parser Created" << std::endl;
}
//�����Ǻ�
Status Parser::Parse()
{
	_pTree = Expr();
	if (!_scanner.IsDone())
		_status = stError;
	return _status;
}
double Parser::Calculate()const
{
	assert(_status == stOK);
	assert(_pTree != 0);
	return _pTree->Calc();
}
//���ʽ
Node* Parser::Expr()
{
	Node* pNode = Term();
	EToken token = _scanner.Token();
	//��
	if (token == tPlus)
	{
		//ʶ����һ���Ǻ�
		_scanner.Accept();
		Node* pRight = Expr();
		pNode = new AddNode(pNode, pRight);
	}
	//��
	else if (token==tMinus)
	{
		_scanner.Accept();
		Node* pRight = Expr();
		pNode = new SubNode(pNode, pRight);
	}
	//��ֵ
	else if (token == tAssign)
	{
		_scanner.Accept();
		Node* pRight = Expr();
		//��ֵ
		if (pNode->IsLvalue())
		{
			pNode = new AssignNode(pNode, pRight);
		}
		else
		{
			_status = stError;
			delete pNode;
			pNode = Expr();
		}
	}
	return pNode;
}
//��
Node* Parser::Term()
{
	Node* pNode = Factor();
	//Term is Factor * Term
	if (_scanner.Token() == tMult)
	{
		_scanner.Accept();
		Node* pRight = Term();
		pNode = new MultNode(pNode, pRight);
	}
	//Term is Factor/Term
	else if (_scanner.Token()==tDivide)
	{
		_scanner.Accept();
		Node* pRight = Term();
		pNode = new DivideNode(pNode, pRight);
	}
	//Term is Factor
	return pNode;
}
//����
Node* Parser::Factor()
{
	Node* pNode;
	EToken token = _scanner.Token();
	//������
	if (token == tLParen)
	{
		_scanner.Accept();//accept '('
		pNode = Expr();
		if (_scanner.Token() != tRParen)
			_status = stError;
		_scanner.Accept();//accept ')'
	}
	//����
	else if (token == tNumber)
	{
		pNode = new NumNode(_scanner.Number());
		_scanner.Accept();
	}
	//���ű���
	else if (token == tIdent)
	{
		char strSymbol[maxSymLen + 1];
		int lenSym = maxSymLen;
		//����symbol��strSymbol
		_scanner.GetSymbolName(strSymbol, lenSym);
		int id = _symTab.Find(strSymbol);
		_scanner.Accept();
		//�������� ��sin(x)
		if (_scanner.Token() == tLParen)
		{
			_scanner.Accept();
			pNode = Expr();
			if (_scanner.Token() == tRParen)
				_scanner.Accept();
			else
				_status = stError;
			if (id != idNotFound && id < _funTab.Size())
			{
				//�������
				pNode = new FunNode(_funTab.GetFun(id), pNode);
			}
			else
			{
				std::cout << "Unknow function\"";
				std::cout << strSymbol << "\"\n";
			}
		}
		else
		{
			if (id == idNotFound)
				id = _symTab.ForcAdd(strSymbol, lenSym);
			pNode = new VarNode(id, _store);
		}
	}
	//һԪ��
	else if (token == tMinus)
	{
		_scanner.Accept();
		pNode = new UMinusNode(Factor());

	}
	else
	{
		_scanner.Accept();
		_status = stError;
		pNode = 0;
	}
	return pNode;
}