#include "SeqList-1.h"
void TestSeqList1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPopBack(&s);//βɾ
	SLPushFront(&s, 4);
	SLInsert(&s, 3, 6);
	SLPrint(&s);

}
//ͷ��n�����ݵ�ʱ�临�Ӷ�O��N^2����β��n�����ݵ�ʱ�临�Ӷ�O��N��
void TestSeqList2()
{

}
int main()
{
	TestSeqList1();
	return 0;
}