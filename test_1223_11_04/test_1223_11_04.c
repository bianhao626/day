#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NC10 大数乘法
char* solve(char* s, char* t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    int retlen = len_s + len_t;
    char* ret = (char*)malloc(sizeof(char) * (retlen + 1));

    memset(ret, '0', retlen);
    ret[retlen] = '\0';

    int i = 0, j = 0;
    int carry;
    char t1, s1, r1;
    for (i = 0; i < len_t; i++)
    {
        t1 = t[len_t - i - 1];
        carry = 0;
        for (j = 0; j < len_s; j++)
        {
            r1 = ret[retlen - i - j - 1];
            s1 = s[len_s - j - 1];

            carry = carry + (r1 - '0') + (s1 - '0') * (t1 - '0');
            ret[retlen - i - j - 1] = (carry % 10) + '0';
            carry /= 10;
        }
        ret[retlen - len_s - i - 1] += carry;
    }

    if ((len_s == 1 && (s[len_s - 1] - '0') == 0) || (len_t == 1 && (t[len_t - 1] - '0') == 0))
    {
        return &ret[retlen - 1];
    }

    if (carry == 0)
    {
        return &ret[1];
    }

    return ret;
}

//NC18 顺时针旋转矩阵
int** rotateMatrix(int** mat, int matRowLen, int* matColLen, int n, int* returnSize, int** returnColumnSizes)
{
    *returnSize = matRowLen;
    int** ret = (int**)malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = matColLen;
    for (int i = 0; i < n; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < matRowLen; i++)
    {
        for (int j = 0; j < (*matColLen); j++)
        {
            ret[j][n - i - 1] = mat[i][j];
        }
    }
    return ret;
}

int main()
{
    char s[] = "99999999999999999999999999999999999999999999999999999999999994";
    char t[] = "9";
    char* ret = solve(s, t);
    printf("%s\n", ret);
    return 0;
}