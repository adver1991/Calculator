#include"SymbolTable.h"
SymbolTable::SymbolTable(int size)
	:_curId(0), 
	_maxId(size), 
	_htab(size + 1),
	_strBuf(size*10)
{
	_offStr = new int[size];
}
SymbolTable::~SymbolTable()
{
	delete[]_offStr;
}

int SymbolTable::ForcAdd(char const * str, int len)
{
	if (_curId == maxStrings || !_strBuf.WillFit(len))
	{
		return idNotFound;
	}
	//_curid�� �ַ�����Ӧ��ID����"one"��ӦID1�����ַ��������������飩���ַ�������ʼ����
	//��_offStr[curID]��ֵ����curID��ֵ��
	_offStr[_curId] = _strBuf.GetOffset();
	_strBuf.Add(str);
	_htab.Add(str, _curId);
	++_curId;
	return _curId - 1;
}
int SymbolTable::Find(char const * str)const
{
	//���ҹ�ϣ��
	List const & list = _htab.Find(str);
	//�ڶ������ϲ���
	for (Link const * pLink = list.GetHead();
		pLink != 0;
		pLink = pLink->Next())
	{
		//ƫ�����������
		int id = pLink->Id();
		//ƫ�������б������ַ������ַ����������е�����
		int offStr = _offStr[id];
		if (_strBuf.IsEqual(offStr, str))
			return id;
	}
	return idNotFound;
}
char const * SymbolTable::GetString(int id)const
{
	assert(id >= 0);
	assert(id < _curId);
	//����ַ����������е�����
	int offStr = _offStr[id];
	return _strBuf.GetString(offStr);
}