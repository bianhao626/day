#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>

//int main()
//{
//	char arr[] = { 'b','i','t' };
//	printf("%d\n", strlen(arr));
//	return 0;
//}

//#include <stdio.h>
//
//int num = 10;
//int main()
//{
//	int num = 1;
//	printf("%d\n", num);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	printf("%d\n", strlen("c:\test\121"));
//	return 0;
//}

//#include <stdio.h>
//
//int max(int a, int b)
//{
//	if (a > b)
//	{
//		return a;
//	}
//	else if (a == b)
//	{
//		return 0;
//	}
//	else
//	{
//		return b;
//	}
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int c = max(a, b);
//	printf("%d\n", c);
//	return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//	int input = 0;
//	scanf("%d", &input);
//	if (input%5 == 0)
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//	int input = 0;
//	scanf("%d", &input);
//	if (input > 0)
//	{
//		printf("-1");
//	}
//	else if (input == 0)
//	{
//		printf("0");
//	}
//	else
//	{
//		printf("1");
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//	char c;
//	scanf("%c", &c);
//	printf("%d", c);
//	return 0;
//}

#include <stdio.h>

int main()
{
	int a;
	while (scanf("%d", &a) != EOF)
	{
		if (a%2 == 0)
		{
			printf("Even\n");
		}
		else
		{
			printf("Odd\n");
		}
	}
	return 0;
}