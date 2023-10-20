#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//牛客网--BC21
//int main() {
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF) { // 注意 while 处理多个 case
//        // 64 位输出请用 printf("%lld") to 
//        printf("%d\n", a + b);
//    }
//    return 0;
//}

//牛客网--BC22
//int main() {
//    int a, b;
//    scanf("%d%d", &a, &b);
//    printf("%d", a / b);
//    return 0;
//}

//牛客网--BC23
//int main() {
//    int a, b;
//    scanf("%d%d", &a, &b);
//    printf("%d", a % b);
//    return 0;
//}

//牛客网--BC24
//int main() {
//    float f;
//    scanf("%f", &f);
//    int a = (int)f % 10;
//    printf("%d", a);
//    return 0;
//}

//牛客网--BC25
//int main() {
//    int number;
//    scanf("%d", &number);
//    printf("%d", 100 * number);
//    return 0;
//}

//牛客网--BC26
//int main() {
//    int a, b;
//    scanf("%d%d", &a, &b);
//    printf("%d %d", a / b, a % b);
//    return 0;
//}

//牛客网--BC27
//int main() {
//    int a;
//    scanf("%d", &a);
//    printf("%d", a % 10);
//    return 0;
//}

//牛客网--BC28
//int main() {
//    int a;
//    scanf("%d", &a);
//
//    a = a % 100;
//    a /= 10;
//    printf("%d", a);
//    return 0;
//}

//牛客网--BC29
//int main() {
//    int x, n;
//    scanf("%d%d", &x, &n);
//    int tmp = (x - 1 + n) % 7 + 1;
//    printf("%d", tmp);
//    return 0;
//}

//牛客网--BC30
int main() {
    int seconds;
    scanf("%d", &seconds);
    if (seconds <= 0 || seconds >= 100000000) {
        return 1;
    }
    int hour = seconds / 3600;
    int minutes = seconds % 3600 / 60;
    int second = seconds % 3600 % 60;
    printf("%d %d %d", hour, minutes, second);
    return 0;
}