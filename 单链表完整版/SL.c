#include "SL.h"

//��ӡһ������
void SListPrint(SLTNode* phead)//���Դ��ݶ���ָ�룬������Ҫ
{
	//����Ϊ�գ�ָ��Ϊ�ա����Բ���Ҫ����assert
	//����cur���ڱ�������
	SLTNode*cur = phead;
	//�����б�
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//���ܱ�֤���ĵ�ַ�������ģ��������á�++��
	}
	printf("\n");
}

//������
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

// ���������
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


//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β
		//����tail��ͷ��β
		newnode->next = *pphead;
		*pphead = newnode;

	}
}

//β�壺ԭβ�����Ҫ�洢��β���ĵ�ַ
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	//�����ڴ˴�����
	//����newnode���ٿռ�
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
		//��β
		//����tail��ͷ��β
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//��ɾ
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}

//βɾ
//void SListPopBack(SLTNode** pphead)//���ʼд��
//{
//
//	SLTNode* tail = *pphead;
//	while (tail->next != NULL)
//	{
//		tail = tail->next;
//	}
//	tail = NULL;
//}
//ɾ���Ļ�������Ҫ��tail���������һ���ڵ�ɾ���������������ǽ������ڶ����׶Σ�prev����nextָ����Ϊ�գ��ٽ����һ���ڵ�free��
//ΪʲôҪfree��ԭ��malloc���ٵĿռ����ڶ����ֶ�����ģ�Ҳ�����ֶ�free�ͷ�  ��Ȼ���ڴ�й©������
void SListPopBack(SLTNode** pphead)//��ȷ��
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


// ��posλ��֮ǰ�����x
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


//��pos�������
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ɾ��posλ�õ�ֵ
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


//posλ��֮��ɾ��
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
