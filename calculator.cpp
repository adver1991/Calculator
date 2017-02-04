#include"SymbolTable.h"
#include"FunctionTable.h"
#include"Store.h"
#include"Scanner.h"
#include"Parser.h"
const int maxBuf = 100;
const int maxSymbols = 40;

int main()
{
	char buf[maxBuf];
	Status status;
	SymbolTable symTab(maxSymbols);
	FunctionTable funTab(symTab, funArr);	
	Store store(maxSymbols, symTab);
	do
	{
		std::cout << "> ";
		std::cin.getline(buf, maxBuf);
		Scanner scanner(buf);
		Parser parser(scanner, store, funTab, symTab);
		status = parser.Eval();
	} while (status != stQuit);
	return 0;
}
