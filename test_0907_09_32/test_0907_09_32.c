#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void FindNumber(int (*arr)[3],int row,int col,int target)
//{
//	int i, j;
//	if (target < arr[0][0] || target > arr[row-1][col-1])
//	{
//		printf("NO");
//	}
//	else
//	{
//		for (i = 0; i < row; i++)
//		{
//			if (target < arr[i][0])
//			{
//				break;
//			}
//		}
//		for (j = 0; j < col; j++)
//		{
//			if (target == arr[i-1][j])
//			{
//				printf("YES");
//				break;
//			}
//		}
//		if (j == col)
//		{
//			printf("NO");
//		}
//	}
//}
//int main()
//{
//	int arr[3][3] = { {3,5,7},{11,13,15},{16,18,19} };
//	int target = 0;
//	scanf("%d", &target);
//	FindNumber(arr, 3, 3, target);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MyStruct
{
	char name[20];
	int age;
}S;

int int_cmp(const void* p1,const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}
int char_cmp(const void* p1, const void* p2)
{
	return (*(char*)p1 - *(char*)p2);
}
int struct_cmp(const void* p1, const void* p2)
{
	return strcmp(((S*)p1)->name, ((S*)p2)->name);
}
int main()
{
	//int arr[] = { 1,3,7,3,4,5,9,2,0 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, len, sizeof(int), int_cmp);

	//char ch[] = "wdascfa";
	//int len = strlen(ch);
	//qsort(ch, len, sizeof(char), char_cmp);
	
	S arr[] = { {"wanggang",20},{"lisi",19},{"zhangmingyang",27}};
	int len = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, len, sizeof(S), struct_cmp);

	printf("%u", sizeof(S));
	//for (size_t i = 0; i < len; i++)
	//{
	//	printf("%c ", ch[i]);
	//}
	return 0;
}