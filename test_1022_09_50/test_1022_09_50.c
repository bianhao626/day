#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//牛客网--BC41
//#define PI 3.14
//#include <math.h>
//int main() {
//    int r;
//    scanf("%d", &r);
//
//    float v = 4 * PI * pow(r, 3) / 3;
//    printf("%.2f", v);
//    return 0;
//}

//牛客网--BC42
//int main() {
//    int hour, minute, k;
//    scanf("%d:%d %d", &hour, &minute, &k);
//
//    hour = ((k / 60) + hour) % 24;
//    minute = k % 60 + minute;
//    if (minute > 60) {
//        hour += 1;
//        minute -= 60;
//    }
//    printf("%02d:%02d", hour, minute);
//    return 0;
//}

//牛客网--BC43
//int main() {
//    int n;
//    scanf("%d", &n);
//    int minute = n / 12 * 4;
//
//    printf("%d", minute + 2);
//    return 0;
//}

//牛客网--BC44
//注意输入数据过大的时候，要使用 long long类型
//int main() {
//    long long n, m;
//    scanf("%lld%lld", &n, &m);
//
//    long long x, y, tmp;
//    n > m ? (x = n, y = m) : (x = m, y = n);
//    while (y != 0) {
//        tmp = x % y;
//        x = y;
//        y = tmp;
//    }
//    long long sum = n * m;
//    printf("%lld", x + (sum / x));
//    return 0;
//}

//牛客网--BC45
//#include <math.h>
//int main() {
//    int n;
//    scanf("%d", &n);
//    int count = 0, tmp = 0;
//    while (n) {
//
//        if ((n % 10) % 2 != 0) {
//            tmp += 1 * pow(10, count);
//        }
//        count++;
//        n = n / 10;
//    }
//    printf("%d", tmp);
//    return 0;
//}

//牛客网--BC46
//int main() {
//    int a, b, c, d;
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//
//    float sum = a * 0.2 + b * 0.1 + c * 0.2 + d * 0.5;
//    printf("%.1f", sum);
//    return 0;
//}

//牛客网--BC47
//int main() {
//    long long a, b, c, d;
//    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
//
//    printf("%lld", (a + b - c) * d);
//    return 0;
//}

//牛客网--BC48
//#include <math.h>
//int main() {
//    int x1, y1;
//    int x2, y2;
//    scanf("%d %d\n%d %d", &x1, &y1, &x2, &y2);
//
//    int x3 = pow(x2 - x1, 2);
//    int y3 = pow(y2 - y1, 2);
//    printf("%d", x3 + y3);
//    return 0;
//}

//牛客网--BC49
//int main() {
//    int a, b;
//    scanf("%d%d", &a, &b);
//    int sum = a % 100 + b % 100;
//    sum %= 100;
//    printf("%d", sum);
//    return 0;
//}

//牛客网--BC50
//多组输入
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n >= 140) {
            printf("Genius");
        }
    }
    return 0;
}