#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//牛客网--BC51
//int main() {
//    int a;
//    while (scanf("%d", &a) != EOF) {
//        if (a >= 60) {
//            printf("Pass\n");
//        }
//        else {
//            printf("Fail\n");
//        }
//    }
//    return 0;
//}

//牛客网--BC52
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        if (n % 2 == 0) {
//            printf("Even\n");
//        }
//        else {
//            printf("Odd\n");
//        }
//    }
//    return 0;
//}

//牛客网--BC53
//int main()
//{
//    char ch = 0;
//    while (scanf("%c", &ch) != EOF)
//    {
//        getchar();
//        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'O' || ch == 'o' || ch == 'i' || ch == 'I' || ch == 'U' || ch == 'u')
//            printf("Vowel\n");
//        else
//            printf("Consonant\n");
//    }
//    return 0;
//}

//牛客网--BC54
//int main() {
//    int x, l, r;
//    scanf("%d %d %d", &x, &l, &r);
//    if (x >= l && x <= r) {
//        printf("true");
//    }
//    else {
//        printf("false");
//    }
//    return 0;
//}

//牛客网--BC55
//int main() {
//    int n;
//    scanf("%d", &n);
//    if (n % 100 == 0) {
//        if (n / 100 % 4 == 0) {
//            printf("yes");
//        }
//        else {
//            printf("no");
//        }
//    }
//    else {
//        if (n % 100 % 4 == 0) {
//            printf("yes");
//        }
//        else {
//            printf("no");
//        }
//    }
//    return 0;
//}

//int main() 
//{ 
//	int a; 
//	scanf("%d",&a); 
//	printf((a%4==0&&a%100!=0)||a%400==0?"yes":"no");
//	return 0; 
//}

//牛客网--BC56
//#include <ctype.h>
//int main() {
//    char ch;
//    scanf("%c", &ch);
//    if (isalpha(ch) != 0) {
//        printf("YES");
//    }
//    else {
//        printf("NO");
//    }
//    return 0;
//}

//牛客网--BC57
//int main() {
//    int year, month;
//    scanf("%4d%2d", &year, &month);
//    if (month >= 3 && month <= 5) {
//        printf("spring");
//    }
//    else if (month >= 6 && month <= 8) {
//        printf("summer");
//    }
//    else if (month >= 9 && month <= 11) {
//        printf("autumn");
//    }
//    else {
//        printf("winter");
//    }
//    return 0;
//}

//牛客网--BC58
//#include <math.h>
//int main() {
//    double w, h;
//    scanf("%lf %lf", &w, &h);
//
//    if ((w / pow(h, 2)) >= 18.5 && (w / pow(h, 2)) <= 23.9) {
//        printf("Normal");
//    }
//    else {
//        printf("Abnormal");
//    }
//    return 0;
//}

//牛客网--BC59
//int main() {
//    int a, b, c, d;
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//    int e, f;
//    e = a > c ? a : c;
//    f = b > d ? b : d;
//    printf("%d", e > f ? e : f);
//    return 0;
//}

//牛客网--BC60
#include <ctype.h>
int main() {
    char tmp;
    while (scanf("%c", &tmp) != EOF) {
        getchar();//多行输入，要使用该函数吸收掉空格
        if (isalpha(tmp) != 0) {
            printf("%c is an alphabet.\n", tmp);
        }
        else {
            printf("%c is not an alphabet.\n", tmp);
        }
    }
    return 0;
}