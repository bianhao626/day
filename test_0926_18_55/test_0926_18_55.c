#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
/*
1、p是函数内部的指针，当除了函数之后，指针p也就消失了，str依旧是空指针
2、malloc开辟的空间没有主动释放，因此会出现内存泄露的问题
*/
//修改-1
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	//传地址
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	//释放空间
//	free(str);
//	str = NULL;
//}

//修改-2
//char* GetMemory()
//{
//	char* p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}



//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	//栈空间地址
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
/*
在函数内部使用上面方式开辟的空间，出函数之后，空间自动释放
因此出现野指针的问题，虽然 str 还是指向该地址，但是此时该地址已经被释放了
*/



//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//内存泄露的问题
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}



//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	//malloc的返回值是需要判断才可以使用(不为空)
//	strcpy(str, "hello");
//	free(str);
//	//释放空间之后，str就是野指针，此时再调用str就是非法访问内存
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}


//typedef struct st_type
//{
//	int i;
//	int a[0];//柔性数组成员
//}type_a;
typedef struct st_type
{
	int i;
	int a[];//柔性数组成员
}type_a;
int main()
{
	printf("%zd", sizeof(type_a));
	return 0;
}