#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d",a);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	while (scanf("%d",&a)!=EOF)
//	{
//		printf("%d\n",a);
//	}
//
//	return 0;
//}

//int main() 
//{
//	int a = 0;
//	while (scanf("%d",&a) == 1)
//	{
//		printf("%d\n",a);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//EOF
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = scanf("%d%d", &a, &b);
//	printf("%d %d\n",a,b);
//	printf("ret=%d\n", ret);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	sum = (n / 12) * 4 + 2;
//	printf("%d", sum);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a[10];
//	int input = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &input);
//		a[i] = input;
//	}
//	for (int j = 9; j >= 0; j--)
//	{
//		printf("%d ", a[j]);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//	int a[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
//	int len = sizeof(a)/sizeof(a[0]);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", a[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
////注意输入数据的大小，int类型可能不够用，需要longlong型的数据类型
////同时输出应当采用lld的格式
//int main() 
//{
//	int n = 0;
//	long long sum = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n ; i++)
//	{
//		sum += i;
//	}
//	printf("%lld", sum);
//	return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//	int a = 0;
//	int b = 0;
//	int c = 0, d = 0;
//	scanf("%d %d", &a, &b);
//	c = a / b;
//	d = a % b;
//	printf("%d %d", c, d);
//	return 0;
//}

#include <stdio.h>

int main() 
{
	float weight = 0;
	float height = 0;
	float BMI = 0;
	scanf("%f %f", &weight, &height);
	BMI = weight / ((height/100)*(height / 100));
	printf("%.2f", BMI);
	return 0;
}