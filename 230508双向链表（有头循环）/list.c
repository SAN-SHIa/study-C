#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("newnode:>");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

LTNode* LTInit(LTNode* phead)
{
	//哨兵位头节点，不存储数据，需要单独创建，在打印时也不需要考虑，打印除它之外的所有
	phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void LTDestroy(LTNode*phead)
{
	if (phead == NULL)
	{
		return;
	}
	LTNode* cur = phead->next;
	while (cur != phead);
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

void LTPrint(LTNode* phead)
{
	if (phead == NULL)
	{
		return;
	}
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//不用像单链表一样探空。只改结构体中的变量，不需要二级指针。
void LTPushBack(LTNode* phead, LTDataType x)
{
	//有可能是空有可能不是空则需要断言；
	//不可能为空则需要assert断言
	//此处Init处理为非空
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void LTPopBack(LTNode* phead)
{
	if ((phead == NULL) || (phead->next == phead))    //排除为空的情况
	{
		return;
	}
	LTNode* tmp = phead->prev;
	LTNode* tmpprev = tmp->prev;
	tmpprev->next = phead;
	phead->prev = tmpprev;
	free(tmp);
	tmp = NULL;
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	if (phead == NULL)
	{
		return;
	}
	LTNode* newnode = BuyListNode(x);
	LTNode* next= phead->next;
	newnode->next = next;
	next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}
void LTPopFront(LTNode* phead)
{
	if ((phead == NULL) || (phead->next == phead))    //排除为空的情况
	{
		return;
	}
	LTNode* tmp = phead->prev;
	LTNode* tmpprev = tmp->prev;

	tmpprev->next = phead;
	phead->prev = tmpprev;
	free(tmp);
	tmp = NULL;
}
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	if (phead == NULL)
	{
		return;
	}
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	if (pos == NULL)
	{
		return;
	}
	LTNode* newnode = BuyListNode(x);
	LTNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

//双向循环链表给定节点后插：
void LTInsertBack(LTNode* pos, LTDataType x)
{
	if (pos == NULL)
	{
		return;
	}
	LTNode* posPrev = pos->next;
	LTNode* newnode = BuyListNode(x);
	posPrev->prev = newnode;
	newnode->next = posPrev;
	newnode->prev = pos;
	pos->next = newnode;
}
//删除指定结点
void LTErase(LTNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
}