#include "SL.h"
void Test1()
{
	SLTNode*plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPopBack(&plist);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 5);
	SListPopFront(&plist);
	SListPrint(plist);
}
int main()
{
	
	Test1();
	return 0;
}