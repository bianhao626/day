#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 28;
//	printf("%d %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d\n", a, b);
//
//	return 0;
//}

//int Figure(int a)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (a&1)
//		{
//			count++;	
//		}
//		a = a >> 1;
//	}
//	return count;
//}
//int main()
//{
//	int a = -1;
//	int ret = Figure(a);
//
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//	int a = 11;
//	int m = a;
//	int n = a;
//	for (int i = 1; i <= 32; i++)
//	{
//		if (i%2==1)
//		{
//			printf("%d ", m & 1);	
//		}
//		m = m >> 1;
//	}
//	printf("\n");
//	for (int i = 1; i <= 32; i++)
//	{
//		if (i % 2 == 0)
//		{
//			printf("%d ", n & 1);
//		}
//		n = n >> 1;
//	}
//
//	return 0;
//}

//int Figure(int a)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (a & 1)
//		{
//			count++;
//		}
//		a = a >> 1;
//	}
//	return count;
//}
//int main()
//{
//	int a;
//	int b;
//	scanf("%d%d", &a, &b);
//	int c = a ^ b;
//	int ret = Figure(c);
//	printf("%d", ret);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    int ret = (++i) + (++i) + (++i);
//    printf("ret = %d\n", ret);
//    return 0;
//}

//#include <stdio.h>
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}

//int main()
//{
//	int year = 0;
//	int m = 0;
//	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	while (scanf("%d%d",&year,&m) == 2)
//	{
//		int d = days[m];
//		if (m == 2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//			{
//				d++;
//			}
//		}
//		printf("%d", d);
//	}
//}

//void my_print(int* p, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	int* p=arr;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	my_print(p, len);
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[10000];
//	gets(arr);
//	int len = strlen(arr);
//
//	char* p = arr;
//	char* left = arr;
//	char* right = arr + len - 1;
//	while (left<right)
//	{
//		char ch = *left;
//		*left = *right;
//		*right = ch;
//		left++;
//		right--;
//	}
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", *(p + i));
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int m, n, sum, num;
//    scanf("%d%d", &m, &n);
//    if (m > n) {
//        num = n;
//    }
//    else {
//        num = m;
//    }
//
//    int arr1[m];
//    int arr2[n];
//    sum = m + n;
//    int arr3[sum];
//
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < m; i++) {
//        scanf("%d", &arr1[i]);
//    }
//    for (j = 0; j < n; j++) {
//        scanf("%d", &arr2[j]);
//    }
//
//    int h = 0;
//    i = j = 0;
//    while (i < m && j < n)
//    {
//        if (arr1[i] < arr2[j])
//        {
//            arr3[h] = arr1[i];
//            h++; i++;
//        }
//        else
//        {
//            arr3[h] = arr2[j];
//            h++; j++;
//        }
//    }
//    if (i == m)
//    {
//        while (j < n)
//        {
//            arr3[h] = arr2[j];
//            h++; j++;
//        }
//    }
//    else
//    {
//        while (i < m)
//        {
//            arr3[h] = arr1[i];
//            h++; i++;
//        }
//    }
//
//    for (int y = 0; y < sum; y++)
//    {
//        printf("%d ", arr3[y]);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int n = 10000;
//	
//	while (n >= 10000 && n <= 99999)
//	{
//		int tmp = n;
//		int sum = 0;
//		for (int i = 1; i <= 4; i++)
//		{
//			sum += (tmp / (int)pow(10, i)) * (tmp % (int)pow(10, i));
//		}
//		if (sum == n)
//		{
//			printf("%d ", n);
//		}
//		n++;
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int len;
//	scanf("%d", &len);
//	for (int i = 1; i <= len; i++)
//	{
//		for (int j =len-i ; j >0 ; j--)
//		{
//			printf(" ");
//		}
//		for (int x = 0; x < 2*i-1; x++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	for (int i = 1; i <= len-1; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (int x = (len-i)*2-1; x >0  ; x--)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i;
//	for (i = 0; i <= 100000; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		while (i /= 10)
//		{
//			count++;
//		}
//		i = tmp;
//		for (int j = 0; j < count; j++)
//		{
//			sum += pow(tmp % 10, count);
//			tmp /= 10;
//		}
//		if (sum==i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	
//	int sn = 0;
//	scanf("%d", &a);
//	int tmp = a;
//	for (int i = 0; i < 5; i++)
//	{
//		sn += tmp;
//		tmp = tmp * 10 + 2;
//	}
//	printf("%d", sn);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int money = 20;
//	int empty = money;
//	int total = money;
//
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d", total);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = 9;
//	
//	while (left<right)
//	{
//		while ((arr[left] % 2 == 1) && (left < right))
//		{
//			left++;
//		}
//		while ((arr[right] % 2 == 0) && (left < right))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//	}
//
//	for (int  i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//char* my_strcpy(char* destination, const char* source)
//{
//	char* dst = destination;
//	while (*source)
//	{
//		*destination++ = *source++;
//	}
//	*destination++ = '\0';
//	return dst;
//}
//int main()
//{
//	char ch1[] = "abcdef";
//	char ch2[] = "ABCD";
//	char *p = my_strcpy(ch1, ch2);
//
//	printf("%s", p);
//	return 0;
//}

#include <stdio.h>
size_t my_strlen(const char* ch)
{
	size_t count = 0;
	while (*ch++)
	{
		count++;
	}
	return count;
}
int main()
{
	char ch[] = "abcdefghijk";
	size_t ret = my_strlen(ch);

	printf("%zu", ret);
	return 0;
}