#include"List.h"
void List::Add(int id)
{
	//�µĽ�㣬�½���ָ����ָ��ͷ���ָ��Ľ��
	Link* pLink = new Link(_pHead, id);
	//ͷָ��ָ���µĽ��
	_pHead = pLink;
}
//�ͷ������ڴ�
List::~List()
{
	while (_pHead != 0)
	{
		Link* pLinkTmp = _pHead;
		_pHead = _pHead->Next();
		delete pLinkTmp;
	}
}
