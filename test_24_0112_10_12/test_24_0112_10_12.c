#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//ÃæÊÔÌâ 08.05. µÝ¹é³Ë·¨
int multiply(int A, int B)
{
    if (A > B)
    {
        int tmp = A;
        A = B;
        B = tmp;
    }
    if (A == 1)
    {
        return B;
    }
    A--;
    return B + multiply(A, B);
}

//int main()
//{
//    int n = multiply(4, 78);
//    printf("%d\n", n);
//	return 0;
//}

//HJ55 Ìô7
int check(int i)
{
    if (i % 10 == 7)
    {
        return 1;
    }
    i /= 10;
    if (i == 0)
    {
        return 0;
    }
    return check(i);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;

    for (int i = 7; i <= n; i++)
    {
        if (i % 7 == 0)
        {
            count++;
            continue;
        }
        else
        {
            if (check(i) == 1)
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}