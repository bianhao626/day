#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//int findMaxConsecutiveOnes(int* nums, int numsSize)
//{
//    int tmp = 0;
//    int count = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 1)
//        {
//            tmp++;
//            if (tmp > count)
//            {
//                count = tmp;
//            }
//        }
//        else
//        {
//            tmp = 0;
//        }
//    }
//    return count;
//}
//int main()
//{
//    int nums[] = { 1,1,0,1,1,1 };
//    int ret = findMaxConsecutiveOnes(nums, 6);
//    printf("%d", ret);
//    return 0;
//}

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int count = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        int sum = 0;
//        for (int j = 1; j <= i; j++)
//        {
//            if (i % j == 0)
//            {
//                sum += j;
//            }
//        }
//        if (sum == i * 2)
//        {
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

//#include <string.h>
//int main()
//{
//    char ch[100];
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    if (n == 0)
//    {
//        ch[i] = '0';
//    }
//    else
//    {
//        while (n)
//        {
//            ch[i++] = (char)(n % 10 + '0');
//            n /= 10;
//        }
//        ch[i] = '\0';
//    }
//    printf("%s", ch);
//    return 0;
//}

int main()
{
    char ch[10000];
    gets(ch);
    int len = strlen(ch);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", ch[i]);
        if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z'))
        {
            printf(" ");
        }
        else
        {
            printf("%c", ch[i]);
        }
    }
    return 0;
}
