#pragma once
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//void LTInit(LTNode**pphead);
LTNode*LTInit();

void LTPrint(LTNode* phead);
bool LTEmpty(LTNode* phead);

void LTPushBack(LTNode* phead,LTDataType x);
void LTPopBack(LTNode*phead);

void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);

//查找
LTNode* LTFind(LTNode* phead,LTDataType x);
//在pos之前插入
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

void LTDestroy(LTNode* phead);
