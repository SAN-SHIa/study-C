#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;//�����ǽṹ�壬���ǽṹ�����͵�ָ�룬��һ���ڵ��ָ�롣�������ڴ˴�ȱ��struct
}SLTNode;

//���Ϸ�д���ȼ�
//struct SListNode 
//{
//	SLTDataType data;
//	struct SListNode* next;
//};
//typedef struct SListNode STLNode



// ��̬����һ���ڵ�
//SListNode* BuySListNode(SLTDateType x);

// �������ӡ
void SListPrint(SLTNode* head);

// ���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x);


// �������ͷ��
void SListPushFront(SLTNode** pplist, SLTDataType x);

// ������β��
void SListPushBack(SLTNode*phead, SLTDataType x);

// ������ͷɾ
void SListPopFront(SLTNode** pplist);

// �������βɾ
void SListPopBack(SLTNode** pplist);


// posλ��ɾ��
void SLTErase(SLTNode** pplist, SLTNode* pos);

// posλ��֮�����
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

// �����������
//void SListDestroy(SLTNode* plist);

// posλ��֮��ɾ��
void SListEraseAfter(SLTNode* pos);
