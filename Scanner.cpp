#include"Scanner.h"

Scanner::Scanner(char const * buf) 
	:_buf(buf), _iLook(0)
{
	std::cout << "Scanner with \"" << buf << "\"" << std::endl;
	Accept();//初始化时调用 *
}
void Scanner::EatWhite()
{
	//isspace—<cctype>
	while (std::isspace(_buf[_iLook]))
		++_iLook;
}
//接受字符并解析
void Scanner::Accept()
{
	EatWhite();
	switch (_buf[_iLook])
	{
	case '+':
		_token = tPlus;
		++_iLook;
		break;
	case '*':
		_token = tMult;
		++_iLook;
		break;
	case '/':
		_token = tDivide;
		++_iLook;
		break;
	case '=':
		_token = tAssign;
		++_iLook;
		break;
	case '(':
		_token = tLParen;
		++_iLook;
		break;
	case ')':
		_token = tRParen;
		++_iLook;
		break;
	case '-':
		_token = tMinus;
		++_iLook;
		break;
	case '0':case '1':case '2':case '3':case '4':
	case '5':case '6':case '7':case '8':case '9':
	case '.':
	{
		_token = tNumber;
		char *p;
		_number = std::strtod(&_buf[_iLook], &p);
		////字符串转整型,atoi()当遇到非数字或字符串结束('\0')才结束转换
		//_number = std::atoi(&_buf[_iLook]);
		/*while (std::isdigit(_buf[_iLook]))
			_iLook++;*/
		_iLook = p - _buf;
		break;
	}
	case '\0':	//结尾
		_token = tEnd;
		break;
	default:
		//字母或下划线
		if (std::isalpha(_buf[_iLook]) || _buf[_iLook] == '_')
		{
			_token = tIdent;
			_iSymbol = _iLook;
			int cLook;
			do{
				++_iLook;
				cLook = _buf[_iLook];
			} while (std::isalnum(cLook) || cLook == '_');//字母、数字、下划线
			_lenSymbol = _iLook - _iSymbol;
			if (_lenSymbol >= maxSymLen)
				_lenSymbol = maxSymLen - 1;
		}
		else
			_token = tError;
		break;
	}
}
//识别标识符的名字
void Scanner::GetSymbolName(char * strOut, int &len)
{
	assert(len >= maxSymLen);
	assert(_lenSymbol < maxSymLen);
	std::strncpy(strOut, &_buf[_iSymbol], _lenSymbol);
	//结尾标识符
	strOut[_lenSymbol] = '\0';
	len = _lenSymbol;
}
bool Scanner::IsDone()const
{
	return _buf[_iLook] == '\0';
}
bool Scanner::IsEmpty()const
{
	return _buf == 0;
}