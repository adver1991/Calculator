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
		std::cout << "> ";//��ʾ
		std::cin.getline(buf, maxBuf);
		Scanner scanner(buf);
		//���벻Ϊ��
		if (!scanner.IsEmpty())
		{
			Parser parser(scanner, store, funTab, symTab);
			status = parser.Parse();
			//�����ɹ�ʱ�ż���
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