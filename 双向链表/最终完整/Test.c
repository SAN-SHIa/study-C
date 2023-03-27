#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
void TestList1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	LTPushFront(plist, 1);
	LTPushFront(plist, 1);
	LTPrint(plist);

}
void TestList2()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);
	LTNode* pos = LTFind(plist, 3);
	if (pos)
	{
		LTErase(pos);
		pos = NULL;
	}
	LTPrint(plist);

}
int main()
{
	//TestList1();
	TestList2();


	return 0;
}