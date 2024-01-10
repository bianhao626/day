#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//OR135 单词缩写
/*
int main()
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char ch[100] = { 0 };
        scanf("%s", ch);
        int len = strlen(ch);
        if (len >= 10)
        {
            int m = len - 2;
            printf("%c%d%c", ch[0], m, ch[len - 1]);
        }
        else
        {
            printf("%s", ch);
        }
        printf("\n");
    }
    return 0;
}
*/

//面试题 01.03.URL化
char* replaceSpaces(char* S, int length)
{
    char* ret = (char*)calloc(3 * length + 1, sizeof(char));
    char* p = ret;
    for (int i = 0; i < length; i++)
    {
        if (S[i] == ' ')
        {
            *p++ = '%';
            *p++ = '2';
            *p++ = '0';
        }
        else
        {
            *p++ = S[i];
        }
    }
    return ret;
}

int main()
{
    char ch[11] = "my   is  a ";
    char* ret = replaceSpaces(ch, 10);
    printf("%s", ret);
    return 0;
}