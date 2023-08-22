#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//void reverse(char* ch, int left, int right)
//{
//    while (left <= right)
//    {
//        char tmp = ch[left];
//        ch[left] = ch[right];
//        ch[right] = tmp;
//        left++;
//        right--;
//    }
//}
//int main()
//{
//    char ch[10001] = { 0 };
//    gets(ch);
//    int len = (int)strlen(ch);
//    reverse(ch, 0, len - 1);
//
//    int left = 0;
//    int right = 0;
//    for (int i = 0; i <= len; i++)
//    {
//        if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z'))
//        {
//            continue;
//        }
//        else
//        {
//            right = i - 1;
//            reverse(ch, left, right);
//            left = i + 1;
//            ch[i] = ' ';
//        }
//    }
//    printf("%s", ch);
//    return 0;
//}

//#include <math.h>
//int main()
//{
//    int n, m;
//    while (scanf("%d %d", &n, &m) != EOF)
//    {
//        double sum = (double)n;
//        double tmp = sum;
//        while (m - 1)
//        {
//            sum += sqrt(tmp);
//            tmp = sqrt(tmp);
//            m--;
//        }
//        printf("%.2f\n", sum);
//    }
//    return 0;
//}

//int main()
//{
//	char* p = "abcd";
//	int len = strlen(p);
//	printf("%d\n", len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c\n", *(p + i));
//	}
//	return 0;
//}

//int* masterMind(char* solution, char* guess, int* returnSize)
//{
//    int* answer = (int*)malloc(sizeof(int) * 2);
//    answer[0] = 0;
//    answer[1] = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        if (*(solution + i) == *(guess + i))
//        {
//            answer[0] += 1;
//            *(solution + i) = '0';
//            *(guess + i) = '1';
//        }
//    }
//    for (int i = 0; i < 4; i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            if (*(guess + j) == *(solution + i))
//            {
//                answer[1] += 1;
//                *(solution + i) = '0';
//                *(guess + j) = '1';
//            }
//        }
//    }
//    *returnSize = 2;
//    return answer;
//}

#include <stdlib.h>
int* twoSum(int* numbers, int numbersLen, int target, int* returnSize)
{
    int* arr = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < numbersLen; i++)
    {
        if (numbers[i] > target)
        {
            continue;
        }
        for (int j = i + 1; j < numbersLen; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                arr[0] = i + 1;
                arr[1] = j + 1;
                *returnSize = 2;
                return arr;
            }
        }
    }
    *returnSize = 0;
    return 0;
}