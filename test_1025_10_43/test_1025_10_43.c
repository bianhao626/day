#include <stdio.h>

//Å£¿ÍÍø--BC69
//int main() {
//    int a;
//    while (scanf("%d", &a) != EOF) {
//        switch (a) {
//        case 200:
//            printf("OK\n");
//            break;
//        case 202:
//            printf("Accepted\n");
//            break;
//        case 400:
//            printf("Bad Request\n");
//            break;
//        case 403:
//            printf("Forbidden\n");
//            break;
//        case 404:
//            printf("Not Found\n");
//            break;
//        case 500:
//            printf("Internal Server Error\n");
//            break;
//        case 502:
//            printf("Bad Gateway\n");
//            break;
//        default:
//            printf("error£¡");
//        }
//    }
//}

//Å£¿ÍÍø--BC70
//int main()
//{
//    float t;
//    while (~scanf("%f", &t))
//    {
//        getchar();
//        if (t > 0)
//            printf("1\n");
//        else if (t == 0)
//            printf("0.5\n");
//        else
//            printf("0\n");
//    }
//    return 0;
//}

//Å£¿ÍÍø--BC71
//int main()
//{
//    int a = 1, b = 1, c = 1;
//
//    while (scanf("%d %d %d", &a, &b, &c) != EOF)
//    {
//        if (a + b > c && a + c > b && b + c > a)
//        {
//            if (a == b && b == c)
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (a == b || b == c || a == c)
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//        {
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//}

//Å£¿ÍÍø--BC72
//int main() {
//    int y, m, d;
//    int y1, m1, d1;
//    scanf("%d%d%d\n%d%d%d", &y, &m, &d, &y1, &m1, &d1);
//
//    if (y1 > y)
//    {
//        printf("yes");
//    }
//    else if (y1 == y)
//    {
//        if (m1 > m)
//        {
//            printf("yes");
//        }
//        else if (m1 == m)
//        {
//            if (d1 >= d)
//            {
//                printf("yes");
//            }
//            else
//            {
//                printf("no");
//            }
//        }
//        else
//        {
//            printf("no");
//        }
//    }
//    else
//    {
//        printf("no");
//    }
//    return 0;
//}

//Å£¿ÍÍø--BC73
//#include <math.h>
//int main()
//{
//    float a = 0.0;
//    float b = 0.0;
//    float c = 0.0;
//    while (scanf("%f %f %f", &a, &b, &c) == 3)
//    {
//        if (a == 0)
//        {
//            printf("Not quadratic equation\n");
//        }
//        else
//        {
//            float deta = b * b - 4 * a * c;
//            if (deta >= 0)
//            {
//                float result1 = (-b + sqrt(deta)) / (2 * a);
//                float result2 = (-b - sqrt(deta)) / (2 * a);
//                if (deta > 0)
//                {
//                    printf("x1=%.2f;x2=%.2f\n", result2, result1);
//                }
//                else
//                {
//                    if (result1 == 0)
//                    {
//                        printf("x1=x2=0.00\n");
//                    }
//                    else
//                    {
//                        printf("x1=x2=%.2f\n", result1);
//                    }
//                }
//            }
//            else
//            {
//                float shibu = (-b) / (2.0 * a);
//                float xubu = (sqrt(-deta)) / (2.0 * a);
//                if (xubu < 0)
//                {
//                    xubu = -xubu;
//                    printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", shibu, xubu, shibu, xubu);
//                }
//                else
//                {
//                    printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", shibu, xubu, shibu, xubu);
//                }
//            }
//        }
//    }
//    return 0;
//}

//Å£¿ÍÍø--BC74
//int main()
//{
//	int year = 0;
//	int m = 0;
//	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	while (scanf("%d%d", &year, &m) == 2)
//	{
//		int d = days[m];
//		if (m == 2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//			{
//				d++;
//			}
//		}
//		printf("%d\n", d);
//	}
//	return 0;
//}

//Å£¿ÍÍø--BC75
//int main() {
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    int average = 0;
//    scanf("%d %d %d", &a, &b, &c);
//    average = (a + b + c) / 3;
//    if (average >= 60) {
//        printf("NO\n");
//    }
//    else {
//        printf("YES\n");
//    }
//    return 0;
//}