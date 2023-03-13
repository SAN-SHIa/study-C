#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fun(int array[], int key, int low, int high)
{

	int mid;
	
	mid = (low + high) / 2;
	if (array[mid] == key)
		return mid;
	else
		return fun(array, key, low + 1, high - 1);
}
int main()
{
	int n;
	int i;
	int arr[200];
	int key;
	int ret;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &key);
	ret = fun(arr, key, 0, n - 1);
	printf("%d", ret);
	return 0;
}
/*int i;
	for (i = 0; i < high; i++)
	{
		if (array[i] == key)
			break;
		else
			return -1;

	}*/
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//void s_count(char str[])
//{
//	int i = 0;
//	int a= 0;
//	int b = 0;
//	int c = 0;
//	int d= 0;
//	while (str[i] != '\0')
//	{
//		if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
//			a++;
//		else if (str[i] >= 48 && str[i] <= 57)
//			b++;
//		else if (str[i] == 32)
//			c++;
//		else
//			d++;
//		i++;
//		
//	}
//	printf("%d %d %d %d", a, b, c, d);
//}
//int main()
//{
//	char str[1000];
//	gets(str);
//	s_count(str);
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void hanio(int n, int x, int y, int z)
//{
//	if (n == 1)
//		printf("move from %c to %c\n", x, z);
//	else
//	{
//		hanio(n - 1, 'a','c','b');
//		printf("move from %c to %c\n", x, z);
//		hanio(n - 1, 'b','a','c');
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a, b, c;
//	hanio(n, 'a', 'b', 'c');
//	return 0;
//}