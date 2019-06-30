typedef int SDataType;
typedef struct SListNode//���
{
	SDataType _data;
	struct SListNode *_PNext;
}Node;
typedef struct SList
{
	Node *PHead;
}SList;
void SListInit(SList *pl);
void SListPushBack(SList *pl, SDataType data);//β��
void SListPopBack(SList *pl);//βɾ
void SListPushFront(SList *pl, SDataType data);//ͷ��
void SListPopFront(SList *pl);//ͷɾ
void SListInsertAfter(Node *pos, SDataType data);//����λ�ò���
void SListErase(SList *pl, Node *pos);//����λ��ɾ��
Node *SListFind(SList *pl, SDataType data);//����
int SListSize(SList *pl);//��Ѱ�ڵ����
Node* SListFront(SList *pl);//��ȡ��һ���ڵ�
Node* SListBack(SList *pl);//���뱣֤��β��㣬��ȡ���һ���ڵ�
void PrintSList(SList *pl);
void SListDestroy(SList *pl);
int SListEmpty(SList *pl);



