#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
void QInit(Q* p)
{
	if (p == NULL)
	return;
	p->head = NULL;
	p->tail = NULL;
}
void QPrint(Q* p)
{
	if (p == NULL)
	{
		printf("queuepush fail\n");
		return;
	}
	QNode* cur = p->head;
	while (cur)
	{
		printf("%d-", cur->data);
		cur=cur->next;
	}
	printf("\n");
}
void QPush(Q* p, QueueDataType x)
{

	if (p == NULL)
	{
		printf("queuepush fail\n");
		return;
	}
	QNode* newnode = (QNode*)malloc(sizeof(QNode));

	/*
	���ҵ��Ķ������ˣ�������ô�����⻻˳����
	newnode->next = null;
	newnode->data = x;
	*/

	newnode->data = x;
	newnode->next = NULL;
	if (p->head == NULL)
	{
		p->head = p->tail = newnode;
	}
	else
	{
		//���½ڵ������ڶ�β��
		p->tail->next = newnode;
		//���¶�β��
		p->tail = newnode;
	}
}
void QPop(Q* p)
{
	if (p == NULL)
	{
		return ;
	}
	QNode* cur = p->head->next;
	free(p->head);
	p->head = NULL;
	p->head = cur;
	if (p->head == NULL)
	{
		p->tail = NULL;
	}
}
QueueDataType QFront(Q* p)
{
	if (p == NULL)
	{
		printf("queuepush fail\n");
		return;
	}
	return p->head->data;
}
QueueDataType QBack(Q* p)
{
	if (p == NULL)
	{
		printf("queuepush fail\n");
		return;
	}
	return p->tail->data;
}
QueueDataType QSize(Q* p)
{
	if (p == NULL)
	{
		printf("queuepush fail\n");
		return;
	}
	int count = 0;
	QNode* cur = p->head;
	while (cur)
	{
		count += 1;
		cur = cur->next;
	}
	return count;
}

void QDestroy(Q* p)
{
	if (p == NULL)
	{
		printf("queuepush fail\n");
		return;
	}
	QNode* cur = p->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = NULL;
	}
	p->head = p->tail = NULL;
}
