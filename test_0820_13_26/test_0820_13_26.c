#include <stdio.h>
//int* selfDividingNumbers(int left, int right)
//{
//    int count = 0;
//    int j = 0;
//    int num[30];
//    for (int i = left; i <= right; i++)
//    {
//        int tmp = i;
//        int flag;
//        while (tmp)
//        {
//            flag = 1;
//            int n = tmp % 10;
//            if (n == 0)
//            {
//                flag = 0;
//                break;
//            }
//            else
//            {
//                if (i % n != 0)
//                {
//                    flag = 0;
//                    break;
//                }
//            }
//            tmp /= 10;
//        }
//        if (flag == 1)
//        {
//            num[j++] = i;
//        }
//    }
//    return num;
//}
//int main()
//{
//    int* arr = selfDividingNumbers(1,22);
//    for (int i = 0; i < 30; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//int* productExceptSelf(int* nums, int numsSize, int* returnSize)
//{
//    int left[numsSize];
//    int right[numsSize];
//
//    left[0] = 1;
//    for (int i = 1; i < numsSize; i++)
//    {
//        left[i] = left[i - 1] * nums[i - 1];
//    }
//    right[numsSize - 1] = 1;
//    for (int i = numsSize - 2; i >= 0; i--)
//    {
//        right[i] = right[i + 1] * nums[i + 1];
//    }
//    int* arr = (int*)malloc(sizeof(int) * numsSize);
//    for (int i = 0; i < numsSize; i++)
//    {
//        arr[i] = left[i] * right[i];
//    }
//    *returnSize = numsSize;
//    return arr;
//}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int hash[numsSize];
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        hash[i] = 0;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[nums[i] - 1] == 0)
        {
            hash[nums[i] - 1] = 1;
        }
    }
    int count = 0;
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[i] == 0)
        {
            count++;
            arr[j++] = i + 1;
        }
    }
    *returnSize = count;
    return arr;
}