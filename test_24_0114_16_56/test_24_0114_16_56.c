#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//OR140 数列
//int main()
//{
//    int tmp[1000001];
//    tmp[1] = 1, tmp[2] = 2;
//    for (int i = 3; i <= 1000001; i++)
//    {
//        tmp[i] = (tmp[i - 1] * 2 + tmp[i - 2]) % 32767;
//    }
//    int n = 0;
//    scanf("%d", &n);
//    for (int j = 0; j < n; j++)
//    {
//        int m = 0;
//        scanf("%d", &m);
//        printf("%d\n", tmp[m]);;
//    }
//    return 0;
//}


//HJ40 统计字符
#include <ctype.h>
#include <string.h>
int main()
{
    char ch[1000] = { 0 };
    gets(ch);
    int len = strlen(ch);
    int count_eng = 0;
    int count_space = 0;
    int count_num = 0;
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (isdigit(ch[i]))
        {
            count_num++;
        }
        else if (isalpha(ch[i]))
        {
            count_eng++;
        }
        else if (ch[i] - ' ' == 0)
        {
            count_space++;
        }
        else
        {
            count++;
        }
    }
    printf("%d\n%d\n%d\n%d\n", count_eng, count_space, count_num, count);
    return 0;
}