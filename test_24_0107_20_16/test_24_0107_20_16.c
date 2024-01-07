#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
#include <stdio.h>

//HJ99自守数
//int main() {
//    int n;
//    scanf("%d", &n);
//    int numbers = 0;
//
//    for (int i = 0; i <= n; i++) {
//        int sum = i * i;
//        int count = 0;
//        int tmp = i;
//        while (tmp) {
//            tmp /= 10;
//            count++;
//        }
//
//        int m = sum % (int)pow(10, count);
//
//        if (m == i) {
//            numbers++;
//        }
//    }
//    printf("%d\n", numbers);
//    return 0;
//}

//OR86 返回小于 N 的质数个数
int main() {
    int n = 0;
    scanf("%d", &n);
    int numbers = 0;

    for (int j = 2; j < n; j++) {
        int m = (int)sqrt(j);
        int flag = 1;
        for (int i = 2; i <= m; i++) {
            if (j % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            numbers++;
        }
    }
    printf("%d\n", numbers);
    return 0;
}