#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//釘人利--BC31
//int main() {
//    int n;
//    scanf("%d", &n);
//    int m = 2 << (n - 1);
//    printf("%d", m);
//    return 0;
//}

//釘人利--BC32
//#include <math.h>
//int main() {
//    int age;
//    scanf("%d", &age);
//    long second = age * 3.156 * pow(10, 7);
//    printf("%ld", second);
//    return 0;
//}

//釘人利--BC33
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    float max = 0, min = 1e9, sum = 0;
//    for (int i = 0; i < n; i++) {
//        float f;
//        scanf("%f", &f);
//        if (f > max) {
//            max = f;
//        }
//        if (f < min) {
//            min = f;
//        }
//        sum += f;
//    }
//
//    printf("%.2f %.2f %.2f", max, min, sum / n);
//    return 0;
//}

//釘人利--BC34
//#include <math.h>
//int main() {
//    int a, b, c;
//    scanf("%d%d%d", &a, &b, &c);
//    float sum = a + b + c;
//    float p = sum / 2;
//    float s = p * (p - a) * (p - b) * (p - c);
//
//    printf("circumference=%.2f area=%.2f", sum, sqrtf(s));
//    return 0;
//}

//釘人利--BC35
//int main() {
//    int n, h, m;
//    scanf("%d%d%d", &n, &h, &m);
//
//    int x = m / h;
//    int y = m % h;
//    if (y != 0) {
//        x += 1;
//    }
//    printf("%d", n - x);
//    return 0;
//}

//釘人利--BC36
//int main() {
//    double f;
//    scanf("%lf", &f);
//    double c = (f - 32) / 9 * 5;
//    printf("%.3lf", c);
//    return 0;
//}

//釘人利--BC37
//int main() {
//    int r;
//    scanf("%d", &r);
//
//    float s = 3.14 * r * r;
//    printf("%.2f", s);
//    return 0;
//}

//釘人利--BC38
//int main() {
//    float r1, r2;
//    scanf("%f%f", &r1, &r2);
//
//    float f = 1 / ((1 / r1) + (1 / r2));
//    printf("%.1f", f);
//    return 0;
//}

//釘人利--BC39
//#define PI 3.14
//int main() {
//    int h, r;
//    scanf("%d%d", &h, &r);
//
//    float v = PI * h * r * r;
//    int c = 10000;
//    int d = 0;
//    while (c > 0) {
//        c = c - v;
//        d++;
//    }
//    printf("%d", d);
//    return 0;
//}

//釘人利--BC40
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int d = b - a;
    printf("%d", b + d);
    return 0;
}