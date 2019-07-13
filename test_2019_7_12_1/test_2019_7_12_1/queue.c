#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = pq->rear = NULL;

}
void QueueDestroy(Queue* pq)//����
{
	QueueNode* cur = NULL;
	assert(pq);
	cur = pq->front;
	while (cur)
	{
		pq->front = cur->next;
		free(cur);
		cur = pq->front;
	}
	pq->front = pq->rear = NULL;
}
QueueNode* BuyQueueNode(QUDataType data)
{
	QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;
}
void QueuePush(Queue* pq, QUDataType data)//���,β��
{
	assert(pq);
	QueueNode* pNewNode = NULL;
	pNewNode = BuyQueueNode(data);
	if (NULL == pq->rear)//�ն���
	{
		pq->front = pq->rear=pNewNode;
	}
	else
	{
		pq->rear->next = pNewNode;
		pq->rear = pNewNode;
	}
}
void QueuePop(Queue* pq)//����
{
	assert(pq);
	if (NULL == pq->front)
	{
		return;
	}
	else if (pq->front==pq->rear)//ֻ��һ���ڵ�
	{
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	else//���Ԫ��
	{
		QueueNode *Del = pq->front;
		pq->front = Del->next;
		free(Del);
	}
}
QUDataType QueueFront(Queue* pq)//��ȡ��ͷԪ��
{
	assert(pq);
	return pq->front->data;
}
QUDataType QueueBack(Queue* pq)//��ȡ��βԪ��
{
	assert(pq);
	return pq->rear->data;
}
int Queuempty(Queue *pq)//�ÿ�
{
	assert(pq);
	return NULL == pq->front;
}
int QueueSize(Queue *pq)//��ȡ��ЧԪ�ظ���
{
	QueueNode* cur = NULL;
	int count = 0;
	assert(pq);
	cur = pq->front;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
void QueueShow(Queue* pq)
{
	QueueNode* cur = NULL;
	assert(pq);
	cur = pq->front;
	while (cur)
	{
		printf("%d---->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}