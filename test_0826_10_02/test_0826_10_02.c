#include <stdio.h>

//void yangHuiTriangle(int n)
//{
//	int data[30] = { 1 };
//
//	int i, j;
//	printf("1\n"); //��һ�о�ֱ�Ӵ�ӡ��
//	for (i = 1; i < n; i++) //�ӵڶ��п�ʼ
//	{
//		for (j = i; j > 0; j--) //�Ӻ���ǰ�������һ�е�������ʹ��ǰ�ͱ�����
//		{
//			data[j] += data[j - 1]; //��ʽͬ�ϣ����ڱ����һά����ʽҲ����ˡ�
//		}
//
//		for (j = 0; j <= i; j++) //��һ�������ֱ�Ӵ�ӡ�ˡ�
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