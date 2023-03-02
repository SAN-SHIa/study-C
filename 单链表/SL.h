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



//// ��̬����һ���ڵ�
//SListNode* BuySListNode(SLTDateType x);

// �������ӡ
void SListPrint(SLTNode* head);

// ������β��
void SListPushBack(SLTNode*phead, SLTDataType x);

// �������ͷ��
void SListPushFront(SLTNode** pplist, SLTDataType x);

// �������βɾ
void SListPopBack(SLTNode** pplist);

// ������ͷɾ
void SListPopFront(SLTNode** pplist);
//// ���������
//SListNode* SListFind(SListNode* plist, SLTDateType x);
//// ��������posλ��֮�����x
//// ����˼��Ϊʲô����posλ��֮ǰ���룿
//void SListInsertAfter(SListNode* pos, SLTDateType x);
//// ������ɾ��posλ��֮���ֵ
//// ����˼��Ϊʲô��ɾ��posλ�ã�
//void SListEraseAfter(SListNode* pos);
//// �����������
//void SListDestroy(SListNode* plist);