//int* getRow(int rowIndex, int* returnSize)
//{
//    *returnSize = rowIndex + 1;
//    int** arr = malloc(sizeof(int*) * (rowIndex + 1));
//    for (int i = 0; i <= rowIndex; i++)
//    {
//        arr[i] = malloc(sizeof(int) * (i + 1));
//
//        arr[i][0] = arr[i][i] = 1;
//        for (int j = 1; j < i; j++)
//        {
//            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//        }
//    }
//    return arr[rowIndex];
//}

#include <stdio.h>
int maxProfit(int* prices, int pricesSize)
{
    //暴力法，但是C的运行时间超出限制
    int i, j;
    int tmp = 0;
    for (i = 0; i < pricesSize; i++)
    {
        for (j = i + 1; j < pricesSize; j++)
        {
            if ((prices[j] - prices[i]) > tmp)
            {
                tmp = prices[j] - prices[i];
            }
        }
    }
    return tmp;
}

int main()
{
    int price[6] = { 7,1,5,3,6,4 };
    int ret = maxProfit(price, 6);
    printf("%d", ret);
    return 0;
}