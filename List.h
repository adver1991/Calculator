//链接（结点）
class Link
{
public:
	Link(Link* pNext, int id) : _pNext(pNext), _id(id){}
	Link* Next()const{	return _pNext;}
	int Id()const{	return _id;}
private:
	Link* _pNext;
	int _id;
};
//链表
class List
{
public:
	//初始化时头指针指向NULL
	List() :_pHead(0){}
	~List();
	//在第一个元素前插入
	void Add(int id);
	Link const *GetHead()const{	return _pHead;}
private:
	//头指针
	Link* _pHead;
};