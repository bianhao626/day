#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//6. Z 字形变换
//方法一
char* convert_1(char* s, int numRows)
{
    int n = strlen(s);
    int r = numRows;
    if (r == 1 || r >= n)
    {
        return s;
    }

    int t = r * 2 - 2;
    int c = (n + t - 1) / t * (r - 1);
    char** tmp = (char**)malloc(sizeof(char*) * r);
    for (int i = 0; i < r; i++)
    {
        tmp[i] = (char*)calloc(c, sizeof(char));
    }

    for (int i = 0, x = 0, y = 0; i < n; i++)
    {
        tmp[x][y] = s[i];
        if (i % t < r - 1)
        {
            x++;
        }
        else
        {
            x--;
            y++;
        }
    }
    int pos = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (tmp[i][j])
            {
                s[pos++] = tmp[i][j];
            }
        }
        free(tmp[i]);
    }
    free(tmp);
    return s;
}

//方法二
char* convert_2(char* s, int numRows)
{
    int n = strlen(s);
    int r = numRows;
    if (r == 1 || r >= n)
    {
        return s;
    }

    int t = r * 2 - 2;
    char* ret = (char*)malloc(sizeof(char) * (n + 1));
    int pos = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; i + j < n; j += t)
        {
            ret[pos++] = s[j + i];
            if (i > 0 && i < r - 1 && j + t - i < n)
            {
                ret[pos++] = s[j + t - i];
            }
        }
    }
    ret[pos] = '\0';
    return ret;
}

int main()
{
    char ch[] = "PAYPALISHIRING";
    //char* ret_1 = convert_1(ch, 3);
    //printf("%s\n", ret_1);
    char* ret_2 = convert_2(ch, 3);
    printf("%s\n", ret_2);
    return 0;
}