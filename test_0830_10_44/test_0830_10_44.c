#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int** generate(int numRows, int* returnSize, int** returnColumnSizes)
//{
//    //����һ����ά����
//    int** arr = malloc(sizeof(int*) * numRows);
//    *returnSize = numRows;
//    *returnColumnSizes = malloc(sizeof(int) * numRows);
//    for (int i = 0; i < numRows; ++i)
//    {
//        arr[i] = malloc(sizeof(int) * (i + 1));
//        (*returnColumnSizes)[i] = i + 1;
//        arr[i][0] = arr[i][i] = 1;
//        for (int j = 1; j < i; ++j)
//        {
//            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//        }
//    }
//    return arr;
//}

/*����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣�*/
//����
//����ˮ���Ȿ������һ����ѧ���ʽ
//��һ�Σ�20
//�ڶ��Σ�10
//�����Σ�5
//���ĴΣ�2--1
//����Σ�1
//�����Σ�1
//�����25Ԫ
//1.25
//2.12--1
//3.6
//4.3
//5.2
//6.1
//��������Ǯ*2-1
int main()
{
	int total = 0;
	int money = 0;
	scanf("%d", &money);
	if (money <= 0)
	{
		total = 0;
	}
	else
	{
		total = money * 2 - 1;
	}
	printf("%d", total);
	return 0;
}