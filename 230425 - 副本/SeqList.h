#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
#define N 10
//��̬˳���
//struct SeqList
//{
//	int a[N];
//	int size;
//};

//��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;//������realloc����
}SeqList;

void SeqListInit(SeqList* p);
void SeqListDestroy(SeqList* p);
void CheckCapacity(SeqList* p);
void SeqListPrint(SeqList* p);

//����ɾ
void SeqListPushBack(SeqList* p,SLDataType x);
void SeqListPushFront(SeqList* p, SLDataType x);
void SeqListPopBack(SeqList* p);
void SeqListPopFront(SeqList* p);

//����
void SeqListFind(SeqList* p, SLDataType x);

//�޸�
void SeqListChange(SeqList* p, SLDataType pos,SLDataType x);






