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

//��ɳ������㣬����Ϊ�������ݣ�ÿ�а�����������a��b���ÿո������
//
//���ÿ�����ݣ����a��b�Ľ��������������룬���b����0�����error
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