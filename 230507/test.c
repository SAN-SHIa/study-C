#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
void test1()
{
	SLNode* plist = NULL;
	SLPushBack(&plist,1);
	SLPushBack(&plist,2);
	SLPushBack(&plist,3);
	SLPushBack(&plist, 4);
	SLPushBack(&plist, 7);
	SLPushBack(&plist, 9);
	SLPushBack(&plist, 6);
	SLPushFront(&plist,4);
	SLPrint(plist);

	SLPopBack(&plist);
	SLPrint(plist);
	SLPopFront(&plist);
	SLPrint(plist);
	SLFind(plist, 4);
	SLInsertFront(&plist, (plist->next)->next,30);
	SLPrint(plist);
	SLInsertAfter((plist->next)->next, 31);
	SLPrint(plist);
	SLErase(&plist, (plist->next)->next);
	SLPrint(plist);
	SLDestory(&plist);
	SLPrint(plist);
}
int main()
{
	test1();
	return 0;
}