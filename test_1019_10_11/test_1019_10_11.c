#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//牛客网--BC7
//int main() {
//    char ch;
//
//    scanf("%c", &ch);
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            printf("%c", ch);;
//        }
//        printf("\n");
//    }
//    return 0;
//}

//牛客网--BC8
//int main() {
//    char ch;
//    scanf("%c", &ch);
//
//    int n = 5;
//    int x, y;
//    for (int i = 1; i <= n; i++)
//    {
//        for (x = n - i; x > 0; x--)
//        {
//            printf(" ");
//        }
//        for (y = 1; y <= 2 * i - 1; y++)
//        {
//            printf("%c", ch);
//        }
//        printf("\n");
//    }
//    for (int i = 1; i < n; i++)
//    {
//        for (y = 1; y <= i; y++)
//        {
//            printf(" ");
//        }
//        for (x = 1; x <= (n-i)*2-1; x++)
//        {
//            printf("%c", ch);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//牛客网--BC9
//int main() {
//    char ch;
//    scanf("%c", &ch);
//
//    printf("%d", ch);
//    return 0;
//}

//牛客网--BC10
int main()
{
    float a;    //浮点参数
    scanf("%f", &a);
    if ((a + 0.5) > ((int)a) + 1)    //判断参数a的第一位小数是否大于或等于0.5
        printf("%d", (int)a + 1);    //判断可以四舍五入，执行a+1
    else if (a - 0.5 < ((int)a) - 1)     //判断负浮点数的能否四舍五入
        printf("%d", (int)a - 1);    //可以，执行a-1
    else                        //参数a不能四舍五入
        printf("%d", (int)a);    //打印原值
    return 0;
}