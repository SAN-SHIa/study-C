#include "SeqList-1.h"
//��ʼ��
void SLInit(SL*ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)*INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("MALLOC FAIL");
		return;
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}

//���ռ��Ƿ��㹻
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)//����
	{
		SLDataType* tmp = (SLDataType*)realloc
		(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("REALLOC FAIL");
			return;
		}
		ps->capacity *= 2;
	}
}

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//βɾ
void SLPopBack(SL* ps)
{
	if (ps->size == 0)
	{
		return 0;
	}
	//ps->a[ps->size - 1] = 0;
	ps->size--;
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	//����
	SLCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}

//����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	//����
	SLCheckCapacity(ps);
	int end = ps->size-1;
	while (pos <= end)
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	
	ps->size++;
}

//ɾ��
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

//����
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//��ӡ
void SLPrint(SL* ps) 
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//����
void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}