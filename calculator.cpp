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
	FunctionTable funTab(symTab);
	Store store(maxSymbols, symTab);
	std::cout << "\n Entry empty line to quit\n";
	do
	{
		std::cout << "> ";//提示
		std::cin.getline(buf, maxBuf);
		Scanner scanner(buf);
		//输入不为空
		if (!scanner.IsEmpty())
		{
			Parser parser(scanner, store, funTab, symTab);
			status = parser.Parse();
			//解析成功时才计算
			if (status == stOK)
			{
				double result = parser.Calculate();
				std::cout << result << std::endl;
			}
			else
			{
				std::cerr << "Syntax error.\n";
			}
		}
		else
		{
			break;
		}
	} while (status != stQuit);
	return 0;
}