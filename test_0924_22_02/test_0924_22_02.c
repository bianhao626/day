#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	//����1
//	int num = 0;
//	scanf("%d", &num);
//	int arr[num] = { 0 };
//	//����2
//	int* ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
//	ptr = NULL;//�Ƿ��б�Ҫ��
//	return 0;
//}

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//ʹ�ÿռ�
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
		//ҵ����
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	//��չ����
	//����1
	ptr = (int*)realloc(ptr, 1000);//����������(�������ʧ�ܻ���Σ�)

	//����2
	int* p = NULL;
	p = realloc(ptr, 1000);
	if (p != NULL)
	{
		ptr = p;
	}
	//ҵ����
	free(ptr);
	return 0;
}
