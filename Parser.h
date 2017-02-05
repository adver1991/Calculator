#ifndef PARSER_H
#define PARSER_H
class Node;
class Scanner;
class SymbolTable;
class Store;
class FunctionTable;
//ö�٣�״̬
enum Status
{
	stOK,
	stQuit,
	stError
};
//��������
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

	Scanner & _scanner;//ɨ����
	SymbolTable & _symTab;//���ű�
	Node* _pTree;//������
	Status _status;//״̬λ
	Store& _store;//�洢��
	FunctionTable& _funTab;//������
};


#endif