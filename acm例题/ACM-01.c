#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a, b = 0;
	while (scanf("%d %d", &a, &b) !=EOF)
	{
		if (b == 0)
		{
			printf("error\n");
		}
		else
		{
			printf("%d\n", (a + (b / 2)) / b);
		}
	}
	return 0;

}

//完成除法运算，输入为多行数据，每行包括两个整数a和b，用空格隔开。
//
//针对每行数据，输出a÷b的结果，结果四舍五入，如果b等于0，输出error
int main()
{
	int a, b = 0;
	while (scanf("%d %d", &a, &b) == 2)
	{
		if (b == 0)
		{
			printf("error\n");
		}
		else
		{
			printf("%d\n", (a + (b / 2)) / b);
		}
	}
	return 0;
}