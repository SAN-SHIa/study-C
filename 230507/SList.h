#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int SLDataType;

typedef struct SListNode//创建结点结构
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

void SLPrint(SLNode* phead);
SLNode* BuyListNode(SLDataType x);
void SLPushBack(SLNode** pphead, SLDataType x);
void SLPushFront(SLNode** pphead, SLDataType x);
void SLPopBack(SLNode** pphead);
void SLPopFront(SLNode** pphead);

void SLFind(SLNode* phead, SLDataType x);
void SLInsertFront(SLNode** phead, SLNode*pos, SLDataType x);
void SLInsertAfter(SLNode* pos, SLDataType x);
void SLErase(SLNode** pphead, SLNode* pos);
void SLDestory(SLNode** pphead);


