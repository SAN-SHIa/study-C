#include "SeqList.h"
#define _CRT_SECURE_NO_WARNINGS 1
//初始化顺序表
void SeqListInit(SeqList* p)
{
	assert(p != NULL);
	p->a = NULL;
	p->size =0;
	p->capacity = 0;
}

//销毁顺序表
void SeqListDestroy(SeqList* p)
{
	assert(p != NULL);
	free(p->a);
	p->a = NULL;
	p->size = 0;
	p->capacity = 0;
}

//检查是否超出存储，并扩建
void CheckCapacity(SeqList* p)
{
	assert(p != NULL);
	if (p->size == p->capacity)
	{
		int newcapacity = 0;
		if (p->capacity == 0)
		{
			newcapacity = p->capacity = 4;
		}
		else
		{
			newcapacity = p->capacity * 2;

		}
		SLDataType* pp = (SLDataType*)realloc(p->a, newcapacity * sizeof(SLDataType));  //扩容
		if (pp == NULL)
		{
			perror("realloc");
		}
		p->a=pp;
		p->capacity = newcapacity;
	}

}

void SeqListPushBack(SeqList* p, SLDataType x)
{
	assert(p != NULL);
	CheckCapacity(p);
	p->a[p->size] = x;
	p->size++;
}

void SeqListPushFront(SeqList* p, SLDataType x)
{
	assert(p != NULL);
	CheckCapacity(p);
	int i = 0;
	for (i = p->size; i > 0; i--)
	{
		p->a[i] = p->a[i - 1];
	}
	p->a[0] = x;
	p->size++;
}

void SeqListPopBack(SeqList* p)
{
	assert(p != NULL);
	if (p->size == 0)
	{
		printf("顺序表中无内容可以删除~");
		return;
	}
	else
	{
		p->size--;
	}
}

void SeqListPrint(SeqList* p)
{
	assert(p != NULL);
	if (p->size == 0)
	{
		printf("顺序表为空");
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i < p->size; i++)
		{
			printf("%d->", p->a[i]);
		}
	}
	printf("\n");
}

void SeqListPopFront(SeqList* p)
{
	assert(p != NULL);
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		p->a[i] = p->a[i + 1];
	}
	p->size--;
}

//查找
void SeqListFind(SeqList* p, SLDataType x)
{
	assert(p != NULL);
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (p->a[i] == x)
		{
			printf("找到啦，查找的%d 在数组中的下标为%d\n",x, i);
		}
	}
}

//修改
void SeqListChange(SeqList* p, SLDataType pos, SLDataType x)
{
	assert(p != NULL);
	p->a[pos] = x;
}



	