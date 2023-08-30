#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int** generate(int numRows, int* returnSize, int** returnColumnSizes)
//{
//    //创建一个二维数组
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

/*喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）*/
//分析
//喝汽水问题本质上是一个数学表达式
//第一次：20
//第二次：10
//第三次：5
//第四次：2--1
//第五次：1
//第六次：1
//如果是25元
//1.25
//2.12--1
//3.6
//4.3
//5.2
//6.1
//归纳问题钱*2-1
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