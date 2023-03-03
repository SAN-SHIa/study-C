#include "SL.h"

//打印一个链表
void SListPrint(SLTNode* phead)//可以传递二级指针，但不需要
{
	//链表为空，指针为空。所以不需要断言assert
	//建立cur用于遍历链表
	SLTNode*cur = phead;
	//遍历列表
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//不能保证结点的地址是连续的，不可以用“++”
	}
	printf("\n");
}

//创造结点
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

// 单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		//建立tail从头找尾
		newnode->next = *pphead;
		*pphead = newnode;

	}
}

//尾插：原尾结点中要存储新尾结点的地址
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	//不可在此处断言
	//建立newnode开辟空间
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		//建立tail从头找尾
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//首删
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}

//尾删
//void SListPopBack(SLTNode** pphead)//我最开始写的
//{
//
//	SLTNode* tail = *pphead;
//	while (tail->next != NULL)
//	{
//		tail = tail->next;
//	}
//	tail = NULL;
//}
//删除的话，是需要将tail（链表最后一个节点删除掉），操作就是将倒数第二个阶段（prev）的next指针置为空，再将最后一个节点free掉
//为什么要free，原因：malloc开辟的空间是在堆上手动申请的，也必须手动free释放  不然有内存泄漏的问题
void SListPopBack(SLTNode** pphead)//正确的
{
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	
	SLTNode* prev = NULL;
	SLTNode* tail = *pphead;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail = NULL;
	prev->next = NULL;
}
//
//void SListPopBack(SLTNode** pphead)
//{
//	SLTNode* tail = *pphead;
//	while (tail->next->next != NULL);
//	{
//		tail = tail->next;
//	}
//	free(tail->next);
//	tail->next = NULL;
//}


// 在pos位置之前面插入x
void SListInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	if (pos == *pphead)
	{
		void SListPushFront(pphead, x);

	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuySLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}


//在pos后面插入
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 删除pos位置的值
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}


//pos位置之后删除
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
