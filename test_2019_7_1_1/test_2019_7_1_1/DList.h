# pragma once
typedef int DLDataType;
typedef struct DListNode//��ͷ˫��ѭ������
{
	struct DListNode *_pPre;
	struct DListNode *_pNext;
	DLDataType _data;
}DLNode;
void DListInit(DLNode**PHead);
void DListPushBack(DLNode *PHead, DLDataType data);//β��
void DListPopBack(DLNode *PHead);//βɾ
void DListPushFront(DLNode *PHead, DLDataType data);//ͷ��
void DListPopFront(DLNode *PHead);//ͷɾ
void DListInsert(DLNode *PHead, DLDataType data);//����λ�ò���
void DListErase(DLNode *PHead);//����λ��ɾ��
void PrintDList(DLNode *PHead);//��ӡ
void DListDestroy(DLNode *PHead);//����


