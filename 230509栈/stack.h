#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int StackDataType;
typedef struct Stack
{
	StackDataType* a;
	int capacity;
	int top;
}ST;
void STInit(ST*p);
void STPush(ST*p, StackDataType x);
void STPop(ST* p);
StackDataType STTop(ST* p);
StackDataType STSize(ST* p);
void STDestroy(ST* p);


