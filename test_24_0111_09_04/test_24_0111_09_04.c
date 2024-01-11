#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//面试题 01.06. 字符串压缩
char* compressString(char* S)
{
    int len = strlen(S);
    if (len <= 2)
    {
        return S;
    }
    char* ans = (char*)calloc(len * 2 + 1, sizeof(char));

    int count = 1;
    int index = 0;
    for (int i = 1; i < len + 1; i++)
    {
        if (S[i] == S[i - 1])
        {
            count++;
        }
        else
        {
            ans[index++] = S[i - 1];
            int num = (int)log10(count) + index;
            index = num;
            while (count)
            {
                ans[num--] = count % 10 + '0';
                count /= 10;
            }
            count = 1;
            index++;
        }
    }
    if (len < strlen(ans))
    {
        return S;
    }
    return ans;
}

//面试题 05.07. 配对交换
int exchangeBits(int num)
{
    int t = 0B01010101010101010101010101010101;
    int h = 0B10101010101010101010101010101010;
    t &= num;
    h &= num;
    t <<= 1;
    h >>= 1;

    int ans = t | h;
    return ans;
}

int main()
{
    char* ch = "abcd";
    char* ret = compressString(ch);
    printf("%s\n", ret);
    int n = 1;
    int m = exchangeBits(n);
    printf("%d\n", m);
    return 0;
}