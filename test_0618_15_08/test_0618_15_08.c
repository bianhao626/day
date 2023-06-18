#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int sum(int a)
//{
//	int c = 0;
//	static int b = 3;
//	c += 1;
//	b += 2;
//	return (a + b + c);
//}
//int main()
//{
//	int i;
//	int a = 2;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d,", sum(a));
//	}
//}

//#include <stdio.h>
//
//int main() 
//{
//	int a, b, c, d;
//	int s1, s2, s3;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//	s1 = a > b ? a : b;
//	s2 = c > d ? c : d;
//	s3 = s1 > s2 ? s1 : s2;
//	printf("%d", s3);
//	return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//	char ch;
//	while (scanf("%c", &ch)!=EOF)
//	{
//		if (ch>='A' && ch<='Z')
//		{
//			printf("%c\n", ch + 32);
//		}
//		else if (ch >= 'a' && ch <= 'z')
//		{
//			printf("%c\n", ch - 32);
//		}
//		else
//		{
//			continue;
//		}
//	}
//	return 0;
//}

#include <stdio.h>

int main() 
{
	char ch;
	while (scanf("%c",&ch)!=EOF)
	{
		if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z'))
		{
			printf("%c is an alphabet.\n", ch);
		}
		else if (ch == '\n')
		{
			continue;
		}
		else
		{
			printf("%c is not an alphabet.\n", ch);
		}
	}
	return 0;
}