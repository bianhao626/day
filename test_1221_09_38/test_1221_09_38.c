#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//NC1 大数加法
char* solve(char* s, char* t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    int size = len_s > len_t ? len_s + 2 : len_t + 2;
    char* ret = (char*)malloc(sizeof(char) * size);
    memset(ret, 0, size);

    int carry = 0;
    int index = 0;

    while (len_s || len_t || carry)
    {
        int num_s = len_s > 0 ? s[--len_s] - '0' : 0;
        int num_t = len_t > 0 ? t[--len_t] - '0' : 0;
        int sum = num_s + num_t + carry;

        ret[index++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    for (int i = 0; i < index / 2; i++)
    {
        char tmp = ret[i];
        ret[i] = ret[index - 1 - i];
        ret[index - 1 - i] = tmp;
    }

    ret[index] = '\0';
    return ret;
}



int main()
{
	char s = '2';
	printf("%c\n", s);
	int sum = (s - '0') * 10;
	printf("%d\n", sum);

    char ch1[] = "1";
    char ch2[] = "999";
    char* ret = solve(ch1, ch2);
    printf("%s\n", ret);
	return 0;
}