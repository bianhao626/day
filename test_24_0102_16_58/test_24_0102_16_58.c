#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//5. 最长回文子串
//方法一动态规划C语言版本
char* longestPalindrome(char* s)
{
    int n = strlen(s);
    if (n < 2)
    {
        return s;
    }

    int maxLen = 1;
    int begin = 0;

    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        arr[i][i] = 1;
    }

    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = L + i - 1;//右边界的下标
            if (j >= n)
            {
                break;
            }
            if (s[i] != s[j])
            {
                arr[i][j] = 0;
            }
            else
            {
                if (j - i < 3)
                {
                    arr[i][j] = 1;
                }
                else
                {
                    arr[i][j] = arr[i + 1][j - 1];
                }
            }

            if (arr[i][j] && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }

    char* ret = (char*)calloc(maxLen+1, sizeof(char));
    for (int i = 0; i < maxLen; i++)
    {
        ret[i] = s[begin + i];
    }
    return ret;
}

int main()
{
    char ch[] = "abbbacd";
    char* ret = longestPalindrome(ch);
    printf("%s\n", ret);
    return 0;
}