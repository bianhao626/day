#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//5. 最长回文子串
//方法二中心扩散C语言版本
int CenterFind(char* s, int left, int* right)
{
    while (left >= 0 && (*right) < strlen(s) && s[left] == s[*right])
    {
        left--;
        (*right)++;
    }
    (*right) - 1;
    return left + 1;
}
char* longestPalindrome(char* s)
{
    int start = 0, end = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        int right1 = i;
        int left1 = CenterFind(s, i, &right1);
        int right2 = i + 1;
        int left2 = CenterFind(s, i, &right2);
        if ((right1 - left1) > (end - start))
        {
            end = right1;
            start = left1;
        }
        if ((right2 - left2) > (end - start))
        {
            end = right2;
            start = left2;
        }
    }
    char* ret = (char*)calloc((end - start + 1), sizeof(char));
    for (int i = 0; i < end - start; i++)
    {
        ret[i] = s[start + i];
    }
    return ret;
}

int main()
{
    char ch[] = "cbbd";
    char* ret = longestPalindrome(ch);
    printf("%s\n", ret);
    return 0;
}