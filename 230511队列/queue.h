#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int QueueDataType;

typedef struct QueueNode
{
	QueueDataType data;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode*head;
	QNode*tail;
}Q;

void QInit(Q*p);
void QPush(Q* p, QueueDataType x);
void QPop(Q* p);
void QPrint(Q* p);
QueueDataType QFront(Q* p);
QueueDataType QBack(Q* p);
QueueDataType QSize(Q* p);
void QDestroy(Q* p);

