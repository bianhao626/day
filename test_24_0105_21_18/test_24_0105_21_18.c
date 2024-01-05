#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//7. 整数反转
//int reverse(int x)
//{
//    int ret = 0;
//    int tmp = 0;
//    while (x)
//    {
//        if (ret < -2147483648 / 10 || ret > 2147483647 / 10)
//        {
//            return 0;
//        }
//        tmp = x % 10;
//        x /= 10;
//        ret = ret * 10 + tmp;
//    }
//    return ret;
//}

int main()
{
    int n = 0;
    scanf("%d", &n);

    int a = 0, b = 1, c = 0;
    while (n--)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%d", a);
	return 0;
}