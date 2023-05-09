#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
test()
{
	ST st;
	STInit(&st);
	STPush(&st,30);
	STPush(&st, 90);
	STPush(&st, 120);
	int a=STTop(&st);
	printf("%d\n", a);
	STPop(&st, 120);
	int b = STTop(&st);
	printf("%d\n", b);
	int size = STSize(&st);
	printf("%d\n", size);



}
int main()
{
	test();
	return 0;
}