typedef int SDataType;
typedef struct SListNode//结点
{
	SDataType _data;
	struct SListNode *_PNext;
}Node;
typedef struct SList
{
	Node *PHead;
}SList;
void SListInit(SList *pl);
void SListPushBack(SList *pl, SDataType data);//尾插
void SListPopBack(SList *pl);//尾删
void SListPushFront(SList *pl, SDataType data);//头插
void SListPopFront(SList *pl);//头删
void SListInsertAfter(Node *pos, SDataType data);//任意位置插入
void SListErase(SList *pl, Node *pos);//任意位置删除
Node *SListFind(SList *pl, SDataType data);//查找
int SListSize(SList *pl);//找寻节点个数
Node* SListFront(SList *pl);//获取第一个节点
Node* SListBack(SList *pl);//必须保证有尾结点，获取最后一个节点
void PrintSList(SList *pl);
void SListDestroy(SList *pl);
int SListEmpty(SList *pl);



