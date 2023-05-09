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
//��ջ
void STPush(ST* p, StackDataType x)
{
	if (p == NULL)
	{
		return;
	}
	//�ж��Ƿ����:
	if (p->top == p->capacity)
	{
		//��̬���٣�
		int NewCapacity = (p->capacity == 0) ? 4 : (p->capacity * 2);
		StackDataType* tmp = realloc(p->a, sizeof(StackDataType) * NewCapacity);
		//�ж��Ƿ񿪱ٳɹ���
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
	//�ﵽѹջҪ��ִ��ѹջ������
	p->a[p->top] = x;
	p->top++;
}
//��ջ
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

