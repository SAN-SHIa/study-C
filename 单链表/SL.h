#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;//并非是结构体，而是结构体类型的指针，下一个节点的指针。不可以在此处缺少struct
}SLTNode;

//与上方写法等价
//struct SListNode 
//{
//	SLTDataType data;
//	struct SListNode* next;
//};
//typedef struct SListNode STLNode



//// 动态申请一个节点
//SListNode* BuySListNode(SLTDateType x);

// 单链表打印
void SListPrint(SLTNode* head);

// 单链表尾插
void SListPushBack(SLTNode*phead, SLTDataType x);

// 单链表的头插
void SListPushFront(SLTNode** pplist, SLTDataType x);

// 单链表的尾删
void SListPopBack(SLTNode** pplist);

// 单链表头删
void SListPopFront(SLTNode** pplist);
//// 单链表查找
//SListNode* SListFind(SListNode* plist, SLTDateType x);
//// 单链表在pos位置之后插入x
//// 分析思考为什么不在pos位置之前插入？
//void SListInsertAfter(SListNode* pos, SLTDateType x);
//// 单链表删除pos位置之后的值
//// 分析思考为什么不删除pos位置？
//void SListEraseAfter(SListNode* pos);
//// 单链表的销毁
//void SListDestroy(SListNode* plist);