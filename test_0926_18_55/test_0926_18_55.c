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
1��p�Ǻ����ڲ���ָ�룬�����˺���֮��ָ��pҲ����ʧ�ˣ�str�����ǿ�ָ��
2��malloc���ٵĿռ�û�������ͷţ���˻�����ڴ�й¶������
*/
//�޸�-1
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	//����ַ
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	//�ͷſռ�
//	free(str);
//	str = NULL;
//}

//�޸�-2
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
//	//ջ�ռ��ַ
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
/*
�ں����ڲ�ʹ�����淽ʽ���ٵĿռ䣬������֮�󣬿ռ��Զ��ͷ�
��˳���Ұָ������⣬��Ȼ str ����ָ��õ�ַ�����Ǵ�ʱ�õ�ַ�Ѿ����ͷ���
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
//	//�ڴ�й¶������
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
//	//malloc�ķ���ֵ����Ҫ�жϲſ���ʹ��(��Ϊ��)
//	strcpy(str, "hello");
//	free(str);
//	//�ͷſռ�֮��str����Ұָ�룬��ʱ�ٵ���str���ǷǷ������ڴ�
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
//	int a[0];//���������Ա
//}type_a;
typedef struct st_type
{
	int i;
	int a[];//���������Ա
}type_a;
int main()
{
	printf("%zd", sizeof(type_a));
	return 0;
}