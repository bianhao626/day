#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//    int year, month, day;
//    int num = 0;
//    scanf("%d %d %d", &year, &month, &day);
//    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//    {
//        for (int i = 0; i < month - 1; i++) {
//            num += arr[i];
//        }
//        if (month <= 2) {
//            printf("%d", num + day);
//        }
//        else {
//            printf("%d", num + day + 1);
//        }
//    }
//    else
//    {
//        for (int i = 0; i < month - 1; i++) {
//            num += arr[i];
//        }
//        printf("%d", num + day);
//    }
//    return 0;
//}

//int main() {
//    int m = 0;
//    scanf("%d", &m);
//    int num = 0;
//    for (int i = 1; i <= m - 1; i++)
//    {
//        num += i;
//    }
//    num = num * 2 + 1;
//
//    for (int j = 0; j < m - 1; j++)
//    {
//        printf("%d+", num);
//        num += 2;
//    }
//    printf("%d", num);
//    return 0;
//}

int main() 
{
    int a1 = 2;
    int an = 0;
    int d = 3;
    int n;
    scanf("%d", &n);
    an = a1 + (n - 1) * d;
    printf("%d", (a1 + an) * n / 2);
    return 0;
}