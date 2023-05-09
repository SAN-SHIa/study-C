#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
void STInit(ST*p)
{
	if (p == NULL)
	{
		return;
	}
	p->a = NULL;
	p->capacity = 0;
	p->top = 0;
}
//入栈
void STPush(ST* p, StackDataType x)
{
	if (p == NULL)
	{
		return;
	}
	//判断是否存满:
	if (p->top == p->capacity)
	{
		//动态开辟：
		int NewCapacity = (p->capacity == 0) ? 4 : (p->capacity * 2);
		StackDataType* tmp = realloc(p->a, sizeof(StackDataType) * NewCapacity);
		//判断是否开辟成功：
		if (tmp == NULL)
		{
			printf("Realloc fail\n");
			exit(-1);
		}
		else
		{
			p->a = tmp;
			p->capacity = NewCapacity;
		}
	}
	//达到压栈要求，执行压栈操作：
	p->a[p->top] = x;
	p->top++;
}
//出栈
void STPop(ST* p)
{
	if (p == NULL)
	{
		return;
	}
	if (p->top > 0)
	{
		p->top--;
	}
}

StackDataType STTop(ST* p)
{
	if (p == NULL)
	{
		exit(-1);
	}
	if (p->top > 0)
	{
		return p->a[p->top - 1];
	}
}

StackDataType STSize(ST*p)
{
	if (p == NULL)
	{
		exit(-1);
	}
	if (p->top > 0)
	{
		return p->top ;
	}
}
void STDestroy(ST* p)
{
	if (p = NULL)
	{
		return;
	}
	free(p->a);
	p->a = NULL;
	p->top = p->capacity = 0;
}

