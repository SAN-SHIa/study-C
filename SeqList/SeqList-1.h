#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
#define N 10
#define INIT_CAPACITY 4
//静态顺序表
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};


//动态顺序表，用到的更多，按需申请
typedef struct SeqList
{
	SLDataType*a;
	int size;    //有效数据个数
	int capacity;//空间容量
}SL;

//增删查改
void SLInit(SL*ps);//初始化
void SLCheckCapacity(SL* ps);//检查&扩容
void SLInsert(SL* ps, int pos, SLDataType x);//插入
void SLPushBack(SL* ps, SLDataType x);//尾插
void SLPopBack(SL* ps);//尾删
void SLPushFront(SL* ps, SLDataType x);//头插
void SLPopFront(SL* ps);//头删
void SLErase(SL* ps, int pos);//删除
int SLFind(SL* ps, SLDataType x);//查找
void SLPrint(SL* ps);//打印
void SLDestroy(SL* ps);//销毁
