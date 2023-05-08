#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
test()
{
	LTNode* plist = LTInit();
	LTPushBack(plist,1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	LTPushFront(plist, 3);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
	printf("%p\n",LTFind(plist, 1));
	LTInsert(plist->next, 30);
	LTPrint(plist);
	LTInsertBack(plist->next, 31);
	LTPrint(plist);
	LTErase(plist->next);
	LTPrint(plist);



}
int main()
{
	test();
	return 0;
}
