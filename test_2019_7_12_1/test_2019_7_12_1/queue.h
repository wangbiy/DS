#pragma once
typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QUDataType data;
}QueueNode;//���
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;
void QueueInit(Queue* pq);//��ʼ��
void QueueDestroy(Queue* pq);//����
void QueuePush(Queue* pq, QUDataType data);//���
void QueuePop(Queue* pq);//����
QUDataType QueueFront(Queue* pq);//��ȡ��ͷԪ��
QUDataType QueueBack(Queue* pq);//��ȡ��βԪ��
int Queuempty(Queue *pq);//�ÿ�
int QueueSize(Queue *pq);//��ȡ��ЧԪ�ظ���
void QueueShow(Queue* pq);//��ʾ