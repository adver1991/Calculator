#include"List.h"
void List::Add(int id)
{
	//新的结点，新结点的指针域指向头结点指向的结点
	Link* pLink = new Link(_pHead, id);
	//头指针指向新的结点
	_pHead = pLink;
}
//释放链表内存
List::~List()
{
	while (_pHead != 0)
	{
		Link* pLinkTmp = _pHead;
		_pHead = _pHead->Next();
		delete pLinkTmp;
	}
}
