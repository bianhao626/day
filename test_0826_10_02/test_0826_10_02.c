#include <stdio.h>

//void yangHuiTriangle(int n)
//{
//	int data[30] = { 1 };
//
//	int i, j;
//	printf("1\n"); //第一行就直接打印了
//	for (i = 1; i < n; i++) //从第二行开始
//	{
//		for (j = i; j > 0; j--) //从后向前填，避免上一行的数据在使用前就被覆盖
//		{
//			data[j] += data[j - 1]; //公式同上，由于变成了一维，公式也变简单了。
//		}
//
//		for (j = 0; j <= i; j++) //这一行填完就直接打印了。
//		{
//			printf("%d ", data[j]);
//		}
//		putchar('\n');
//	}
//}

int removeDuplicates(int* nums, int numsSize)
{
    int right = 0;
    int tmp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[tmp] == nums[right])
        {
            right++;
        }
        else
        {
            nums[++tmp] = nums[right];
            right++;
        }
    }
    return tmp + 1;
}
int main()
{
    int nums[] = { 0,0,1,1,1,2,2,3,3,4 };
    int ret = removeDuplicates(nums,10);
    printf("%d", ret);
    return 0;
}