#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//Å£¿ÍÍø--BC61
//int main()
//{
//    int ch;
//    scanf("%d", &ch);
//    if (ch % 2 == 0)
//        printf("2 ");
//    if (ch % 3 == 0)
//        printf("3 ");
//    if (ch % 7 == 0)
//        printf("7 ");
//    if (ch % 7 != 0 && ch % 3 != 0 && ch % 2 != 0)
//        printf("n");
//    return 0;
//}

//Å£¿ÍÍø--BC62
//int main() {
//    int arr[10] = { 0 };
//    int p = 0, n = 0;
//    for (int i = 0; i < 10; i++) {
//        scanf("%d", arr + i);
//        if (arr[i] > 0) {
//            p++;
//        }
//        else {
//            n++;
//        }
//    }
//    printf("positive:%d\n", p);
//    printf("negative:%d\n", n);
//    return 0;
//}

//Å£¿ÍÍø--BC63
//int main() {
//    float f;
//    int year;
//    int month;
//    int n;
//    scanf("%f %d %d %d", &f, &year, &month, &n);
//    if ((year == 11 && month == 11) || (year == 12 && month == 12))
//    {
//        if (year == 11) {
//            f = f * 0.7;
//        }
//        else {
//            f = f * 0.8;
//        }
//        if (n == 1) {
//            f -= 50;
//        }
//    }
//    if (f < 0) {
//        f = 0;
//    }
//    printf("%.2f", f);
//    return 0;
//}

//Å£¿ÍÍø--BC64
//int main() {
//    float a;
//    char b;
//    scanf("%f %c", &a, &b);
//    float i = 0;
//    int money = 0;
//    if (a > 1) {
//        while (i < a) {
//            i++;
//        }
//        money = 20 + (i - 1);
//    }
//    else {
//        money = 20;
//    }
//    money = b == 'y' ? money + 5 : money;
//    printf("%d", money);
//    return 0;
//}

//Å£¿ÍÍø--BC65
//C++´úÂë
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main() {
//
//    double price;
//    cin >> price;
//
//    double cost = 0.0;
//
//    if (price >= 100 && price < 500) {
//        cost = price * 0.9;
//    }
//    else if (price >= 500 && price < 2000) {
//        cost = price * 0.8;
//    }
//    else if (price >= 2000 && price < 5000) {
//        cost = price * 0.7;
//    }
//    else if (price >= 5000) {
//        cost = price * 0.6;
//    }
//
//
//    cout << setiosflags(ios::fixed) << setprecision(1) << cost << endl;
//
//    return 0;
//}

//Å£¿ÍÍø--BC66
//int main() {
//    float n;
//    scanf("%f", &n);
//
//    if (n > n / 10 + 10) {
//        printf("v");
//    }
//    else {
//        printf("w");
//    }
//    return 0;
//}

//Å£¿ÍÍø--BC67
//int main()
//{
//    int x, y, x1, y1;
//    scanf("%d %d", &x, &y);
//    scanf("%d %d", &x1, &y1);
//    if (x1 == x)
//        y1 > y ? printf("u") : printf("d");
//    else
//        x1 > x ? printf("r") : printf("l");
//    return 0;
//}

//Å£¿ÍÍø--BC68
//int main()
//{
//    int a;
//    scanf("%d", &a);
//    switch (a)
//    {
//    case 1:printf("Monday"); break;
//    case 2:printf("Tuesday"); break;
//    case 3:printf("Wednesday"); break;
//    case 4:printf("Thursday"); break;
//    case 5:printf("Friday"); break;
//    case 6:printf("Saturday"); break;
//    case 7:printf("Sunday");
//    }
//    return 0;
//}

