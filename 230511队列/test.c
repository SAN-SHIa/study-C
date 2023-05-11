#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
void test()
{
	Q q;
	QInit(&q);
	QPush(&q, 1);
	QPush(&q, 2);
	QPush(&q, 3);
	QPrint(&q);
	QPush(&q, 4);
	QPop(&q);
	QPrint(&q);
	QPop(&q);
	int a=QFront(&q);
	int b=QBack(&q);
	QPrint(&q);
	printf("队头是%d\n", a);
	printf("队尾是%d\n", b);
	int size = QSize(&q);
	printf("队伍长度为%d个数据", size);
}
int main()
{
	test();
	return 0;
}