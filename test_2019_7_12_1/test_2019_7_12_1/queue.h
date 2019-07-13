#pragma once
typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QUDataType data;
}QueueNode;//结点
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;
void QueueInit(Queue* pq);//初始化
void QueueDestroy(Queue* pq);//销毁
void QueuePush(Queue* pq, QUDataType data);//入队
void QueuePop(Queue* pq);//出队
QUDataType QueueFront(Queue* pq);//获取队头元素
QUDataType QueueBack(Queue* pq);//获取队尾元素
int Queuempty(Queue *pq);//置空
int QueueSize(Queue *pq);//获取有效元素个数
void QueueShow(Queue* pq);//显示