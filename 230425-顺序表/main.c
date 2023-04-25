#include "SeqList.h"
#define _CRT_SECURE_NO_WARNINGS 1
int main()
{
	SeqList S;
	SeqListInit(&S);
	SeqListPushBack(&S,1);
	SeqListPushBack(&S, 2);
	SeqListPushBack(&S, 3);
	SeqListPrint(&S);
	SeqListPopBack(&S);
	SeqListPopBack(&S);
	SeqListPrint(&S);
	SeqListPushFront(&S,2);
	SeqListPushFront(&S,3);
	SeqListPrint(&S);
	//SeqListPopFront(&S);
	//SeqListPopFront(&S);
	//SeqListPopFront(&S);
	SeqListPrint(&S);
	//SeqListFind(&S, 2);
	SeqListFind(&S,1);
	SeqListFind(&S, 1);
	SeqListPrint(&S);
	SeqListChange(&S, 0, 5);
	SeqListChange(&S, 1, 2);
	SeqListChange(&S, 2, 0);
	SeqListPrint(&S);


	SeqListDestroy(&S);

	return 0;
}