//���ӣ���㣩
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
//����
class List
{
public:
	//��ʼ��ʱͷָ��ָ��NULL
	List() :_pHead(0){}
	~List();
	//�ڵ�һ��Ԫ��ǰ����
	void Add(int id);
	Link const *GetHead()const{	return _pHead;}
private:
	//ͷָ��
	Link* _pHead;
};