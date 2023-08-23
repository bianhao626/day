#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//    int n = 0;
//    int num = 0;
//    scanf("%d", &n);
//    int* arr = (int*)malloc(sizeof(int) * n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", arr + i);
//        //两个相同的数异或的结果为0
//        num ^= arr[i];
//    }
//    printf("%d\n", num);
//    return 0;
//}

//int findPeakElement(int* nums, int numsLen)
//{
//    int i = 0;
//    if (nums[0] > nums[1])
//    {
//        return 0;
//    }
//    else if (nums[numsLen - 1] > nums[numsLen - 2])
//    {
//        return numsLen - 1;
//    }
//    for (i = 1; i < numsLen - 1; i++)
//    {
//        if ((nums[i - 1] < nums[i]) && (nums[i + 1] < nums[i]))
//        {
//            break;
//        }
//    }
//    return i;
//}

#include <stdio.h>

//int main()
//{
//    char ch[1000];
//    gets(ch);
//    int k = 0;
//    scanf("%d", &k);
//    ch[k] = '\0';
//    printf("%s", ch);
//    return 0;
//}

#include <stdio.h>

int main()
{
    long n, k;
    scanf("%ld%ld", &n, &k);
    long count = 0;
    if (k == 0)
    {
        printf("%ld\n", n * n);
    }
    else
    {
        for (long y = k + 1; y <= n; y++)
        {
            count += ((n / y) * (y - k)) + ((n % y >= k) ? (n % y - k + 1) : 0);
        }
        printf("%ld\n", count);
    }

    return 0;
}