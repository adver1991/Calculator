#ifndef PARSER_H
#define PARSER_H
class Node;
class Scanner;
class SymbolTable;
class Store;
class FunctionTable;
//Ã¶¾Ù£º×´Ì¬
enum Status
{
	stOK,
	stQuit,
	stError
};
//½âÎöÆ÷Àà
class Parser
{
public:
	Parser(Scanner & scanner,
		Store& store,
		FunctionTable& funTab,
		SymbolTable & symTab);
	~Parser();
	Status Eval();
private:
	void Parse();
	Node* Expr();
	Node* Term();
	Node* Factor();
	void Execute();

	Scanner & _scanner;//É¨ÃèÆ÷
	SymbolTable & _symTab;//·ûºÅ±í
	Node* _pTree;//ËãÊõÊ÷
	Status _status;//×´Ì¬Î»
	Store& _store;//´æ´¢Æ÷
	FunctionTable& _funTab;//º¯Êı±í
};


#endif