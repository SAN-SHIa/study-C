#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
void SLPrint(SLNode* phead)//��curѭ������
{
	SLNode* cur = phead;
	while (cur)//cur���ڻ��Զ����е�null�ı���
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* BuyListNode(SLDataType x)//�൱��Ҫ���ȿ����Ƿ�Ϊ�����ȥ���ǽ�����
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	//�˴�����
	if (newnode == NULL)
	{
		perror("newnode:>");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLPushBack(SLNode** pphead, SLDataType x)//����һ�����飬���������鷳
{
	SLNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else 
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;

	}
}
void SLPushFront(SLNode** pphead, SLDataType x)//�����ɣ�ֻ��ĸ�������Ƽ���
{
	SLNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
void SLPopBack(SLNode** pphead)//�Ƚϸ��ӣ���Ҫ�������������������
{
	if (*pphead == NULL)//���޽��ֱ�ӷ��ؿ�
	{
		return;
	}
	if ((*pphead)->next == NULL)//��һһ����㣬��free��null
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//��������Ҫ�ҵ�β�ͣ������ÿգ����轫ǰһ�����ô���
	{
		SLNode* tail = *pphead;
		SLNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}
void SLPopFront(SLNode** pphead)//��Ϊ��ֻ���ͷ�
{
	if (*pphead == NULL)//���޽��ֱ�ӷ��ؿ�
	{
		return;
	}
	else
	{
		SLNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = NULL;
		*pphead = next;
	}
}


void SLFind(SLNode* phead, SLDataType x)
{
	SLNode* cur = phead;
	int count = 1;
	while (cur)
	{
		if (cur->data == x)
		{
			printf("��%d���ڵ㣺%p -> %d\n", count++, cur, x);
		}
		cur = cur->next;
	}
}
void SLInsertFront(SLNode** pphead, SLNode* pos, SLDataType x)
{
	SLNode* newnode = BuyListNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLNode* post = *pphead;
		while (post->next != pos)
		{
			post = post->next;
		}
		post->next = newnode;
		newnode->next = pos;
	}
}

void SLInsertAfter(SLNode* pos, SLDataType x)
{
	SLNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}


void SLErase(SLNode** pphead, SLNode* pos)
{
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLDestory(SLNode** pphead)
{
	SLNode* cur = *pphead;
	if (*pphead = NULL)
	{
		return;
	}
	else
	{
		while (cur)
		{
			SLNode* next = cur->next;
			free(cur);
			cur = NULL;
			cur = next;
		}
	}
	*pphead = NULL;
}

