#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//ţ����--BC7
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

//ţ����--BC8
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

//ţ����--BC9
//int main() {
//    char ch;
//    scanf("%c", &ch);
//
//    printf("%d", ch);
//    return 0;
//}

//ţ����--BC10
int main()
{
    float a;    //�������
    scanf("%f", &a);
    if ((a + 0.5) > ((int)a) + 1)    //�жϲ���a�ĵ�һλС���Ƿ���ڻ����0.5
        printf("%d", (int)a + 1);    //�жϿ����������룬ִ��a+1
    else if (a - 0.5 < ((int)a) - 1)     //�жϸ����������ܷ���������
        printf("%d", (int)a - 1);    //���ԣ�ִ��a-1
    else                        //����a������������
        printf("%d", (int)a);    //��ӡԭֵ
    return 0;
}