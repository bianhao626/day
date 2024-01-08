#include <stdio.h>
#include <stdbool.h>

//NC31 ��һ��ֻ����һ�ε��ַ�
int FirstNotRepeatingChar(char* str)
{
    int arr[57] = { 0 };
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        arr[*(str + i) - 'A'] += 1;
    }

    for (int i = 0; *(str + i) != '\0'; i++)
    {
        if (arr[*(str + i) - 'A'] == 1)
        {
            return i;
        }
    }
    return -1;
}

//������ 01.01. �ж��ַ��Ƿ�Ψһ
bool isUnique_1(char* astr)
{
    //����Ĺ�ϣ��
    int tmp[26] = { 0 };
    for (int i = 0; *(astr + i); i++)
    {
        if (tmp[*(astr + i) - 'a'] == 1)
        {
            return false;
        }
        tmp[*(astr + i) - 'a'] += 1;
    }
    return true;
}
bool isUnique_2(char* astr)
{
    //λ����
    int mask = 0;
    while (*astr)
    {
        int bit = 1 << (*astr - 'a');
        if ((mask & bit) != 0)
        {
            return false;
        }
        mask |= bit;
        astr++;
    }
    return true;
}

int main()
{
    char ch[] = "abc";
    int n = FirstNotRepeatingChar(ch);
    printf("%d\n", n);
    bool m = isUnique_2(ch);
    printf("%d\n", m);
    return 0;
}