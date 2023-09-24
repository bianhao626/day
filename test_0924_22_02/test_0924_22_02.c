#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	//代码1
//	int num = 0;
//	scanf("%d", &num);
//	int arr[num] = { 0 };
//	//代码2
//	int* ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//是否有必要？
//	return 0;
//}

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//使用空间
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

int main()
{
	int* ptr = (int*)malloc(100);
	if (ptr != NULL)
	{
		//业务处理
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	//扩展容量
	//代码1
	ptr = (int*)realloc(ptr, 1000);//这样可以吗？(如果申请失败会如何？)

	//代码2
	int* p = NULL;
	p = realloc(ptr, 1000);
	if (p != NULL)
	{
		ptr = p;
	}
	//业务处理
	free(ptr);
	return 0;
}
