#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
#define N 10
#define INIT_CAPACITY 4
//��̬˳���
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};


//��̬˳����õ��ĸ��࣬��������
typedef struct SeqList
{
	SLDataType*a;
	int size;    //��Ч���ݸ���
	int capacity;//�ռ�����
}SL;

//��ɾ���
void SLInit(SL*ps);//��ʼ��
void SLCheckCapacity(SL* ps);//���&����
void SLInsert(SL* ps, int pos, SLDataType x);//����
void SLPushBack(SL* ps, SLDataType x);//β��
void SLPopBack(SL* ps);//βɾ
void SLPushFront(SL* ps, SLDataType x);//ͷ��
void SLPopFront(SL* ps);//ͷɾ
void SLErase(SL* ps, int pos);//ɾ��
int SLFind(SL* ps, SLDataType x);//����
void SLPrint(SL* ps);//��ӡ
void SLDestroy(SL* ps);//����
