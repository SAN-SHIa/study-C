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
	printf("��ͷ��%d\n", a);
	printf("��β��%d\n", b);
	int size = QSize(&q);
	printf("���鳤��Ϊ%d������", size);
}
int main()
{
	test();
	return 0;
}