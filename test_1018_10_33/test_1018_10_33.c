#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	FILE* pf;//创建一个文件指针
//	char ch[] = "hello,world!!";
//	pf = fopen("test.txt", "wb");//打开一个文本文件，进行写入操作
//
//	fwrite(ch, sizeof(ch), 1, pf);
//	fclose(pf);
//
//	return 0;
//}

//int main()
//{
//	printf("file:%s line:%d\n", __FILE__, __LINE__);
//	return 0;
//}

//#define MAX 1000
//int main()
//{
//	printf("%d", MAX);
//	return 0;
//}

#define MAX(x,y) ((x)+(y))
int main()
{
	int a = 10;
	int b = 12;
	printf("%d", 10 * MAX(a, b));
	return 0;
}