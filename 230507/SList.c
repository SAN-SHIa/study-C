#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
void SLPrint(SLNode* phead)//用cur循环遍历
{
	SLNode* cur = phead;
	while (cur)//cur用于会自动进行到null的遍历
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* BuyListNode(SLDataType x)//相当重要，先考虑是否为首项，再去考虑接数据
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	//此处不懂
	if (newnode == NULL)
	{
		perror("newnode:>");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLPushBack(SLNode** pphead, SLDataType x)//遍历一遍数组，不过不算麻烦
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
void SLPushFront(SLNode** pphead, SLDataType x)//很轻松，只需改个结点名称即可
{
	SLNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
void SLPopBack(SLNode** pphead)//比较复杂，需要遍历链表，考虑三种情况
{
	if (*pphead == NULL)//若无结点直接返回空
	{
		return;
	}
	if ((*pphead)->next == NULL)//有一一个结点，先free再null
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//多个结点需要找到尾巴，将其置空，还需将前一个做好处理
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
void SLPopFront(SLNode** pphead)//较为简单只需释放
{
	if (*pphead == NULL)//若无结点直接返回空
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
			printf("第%d个节点：%p -> %d\n", count++, cur, x);
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

