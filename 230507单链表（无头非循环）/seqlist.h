#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int LTDataType;

typedef struct SListNode//创建结点结构
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* LTInit();
void LTDestroy(LTNode* phead);
void LTPrint(LTNode* phead);
LTNode* BuyListNode(LTDataType x);
void LTPushBack(LTNode*phead,LTDataType x);
void LTPopBack(LTNode* phead);
void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);


//查找
LTNode* LTFind(LTNode* phead, LTDataType x);
//在指定位置之前插入
void LTInsert(LTNode* pos, LTDataType x);
//指定结点之后
void LTInsertBack(LTNode* pos, LTDataType x);
//删除指定结点
void LTErase(LTNode* pos);

