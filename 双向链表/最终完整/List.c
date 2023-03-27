#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if(node==NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	node->data = x;

	return node;

}

LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("<= head =>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d <=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);

	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	//LTInsert(phead,x);
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	//1
	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail =NULL;
	//2
	/*LTErase(phead->prev);*/

}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyListNode(x);

	newnode->next = phead->next;
	phead->next->prev = newnode;

	phead->next = newnode;
	newnode->prev = phead;

	//LTInsert(phead->next,x);

}

void LTPopFront(LTNode* phead)
{
	LTErase(phead->next);
}

//查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//在pos之前插入一个值
void LTInsert(LTNode* pos,LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* p = pos -> prev;
	LTNode* n = pos->next;
	p->next = n;
	n->prev = p;
	free(pos);
	pos = NULL;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
