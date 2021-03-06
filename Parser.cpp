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
//解析记号
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
//表达式
Node* Parser::Expr()
{
	Node* pNode = Term();
	EToken token = _scanner.Token();
	//加
	if (token == tPlus)
	{
		//识别下一个记号
		_scanner.Accept();
		Node* pRight = Expr();
		pNode = new AddNode(pNode, pRight);
	}
	//减
	else if (token==tMinus)
	{
		_scanner.Accept();
		Node* pRight = Expr();
		pNode = new SubNode(pNode, pRight);
	}
	//赋值
	else if (token == tAssign)
	{
		_scanner.Accept();
		Node* pRight = Expr();
		//左值
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
//项
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
//因子
Node* Parser::Factor()
{
	Node* pNode;
	EToken token = _scanner.Token();
	//左括号
	if (token == tLParen)
	{
		_scanner.Accept();//accept '('
		pNode = Expr();
		if (_scanner.Token() != tRParen)
			_status = stError;
		_scanner.Accept();//accept ')'
	}
	//数字
	else if (token == tNumber)
	{
		pNode = new NumNode(_scanner.Number());
		_scanner.Accept();
	}
	//符号变量
	else if (token == tIdent)
	{
		char strSymbol[maxSymLen + 1];
		//int lenSym = maxSymLen;
		//复制symbol到strSymbol,lenSym为字符长
		int lenSym=_scanner.GetSymbolName(strSymbol, maxSymLen+1);
		int id = _symTab.Find(strSymbol);
		_scanner.Accept();
		//函数调用 如sin(x)
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
				//函数结点
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
			{
				id = _symTab.ForcAdd(strSymbol);
				if (id == idNotFound)
				{
					std::cerr << "Error:Too many variables\n";
					_status = stError;
					pNode = 0;
				}
			}
			if (id != idNotFound)
			{
				pNode = new VarNode(id, _store);
			}
		}
	}
	//一元减
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