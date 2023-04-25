#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
#define N 10
//静态顺序表
//struct SeqList
//{
//	int a[N];
//	int size;
//};

//动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;//可以用realloc扩容
}SeqList;

void SeqListInit(SeqList* p);
void SeqListDestroy(SeqList* p);
void CheckCapacity(SeqList* p);
void SeqListPrint(SeqList* p);

//增与删
void SeqListPushBack(SeqList* p,SLDataType x);
void SeqListPushFront(SeqList* p, SLDataType x);
void SeqListPopBack(SeqList* p);
void SeqListPopFront(SeqList* p);

//查找
void SeqListFind(SeqList* p, SLDataType x);

//修改
void SeqListChange(SeqList* p, SLDataType pos,SLDataType x);






