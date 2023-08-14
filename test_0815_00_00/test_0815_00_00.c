#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int* findErrorNums(int* nums, int numsSize, int* returnSize)
//{
//    int* arr = (int*)malloc(2 * sizeof(int));
//    *returnSize = 2;
//    int* arr1 = (int*)calloc(numsSize, sizeof(int));
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        arr1[nums[i] - 1] += 1;
//    }
//    for (i = 0; i < numsSize; i++)
//    {
//        if (arr1[i] == 2)
//        {
//            arr[0] = i + 1;
//        }
//        if (arr1[i] == 0)
//        {
//            arr[1] = i + 1;
//        }
//    }
//    return arr;
//}

#include <string.h>
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int j = 0; j < n; j++)
        {
            char pwd[100];
            scanf("%s", pwd);
            int lower = 0, higher = 0, number = 0, other = 0;
            if (pwd[0] >= '0' && pwd[0] <= '9')
            {
                printf("NO\n");
                continue;
            }
            if (strlen(pwd) < 8)
            {
                printf("NO\n");
                continue;
            }
            for (int i = 0; pwd[i] != '\0'; i++)
            {
                if (pwd[i] >= '0' && pwd[i] <= '9')
                {
                    number = 1;
                }
                else if (pwd[i] >= 'a' && pwd[i] <= 'z')
                {
                    lower = 1;
                }
                else if (pwd[i] >= 'A' && pwd[i] <= 'Z')
                {
                    higher = 1;
                }
                else
                {
                    other = 1;
                }
            }
            if (other == 1)
            {
                printf("NO\n");
                continue;
            }
            if ((lower + higher + number) < 2)
            {
                printf("NO\n");
                continue;
            }
            printf("YES\n");
        }
    }
    return 0;
}