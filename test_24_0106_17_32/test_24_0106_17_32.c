#include <stdio.h>
#include <stdlib.h>

//8. ×Ö·û´®×ª»»ÕûÊý (atoi)
int myAtoi(char* s)
{
    if (*s == '\0')
    {
        return 0;
    }
    while (*s == ' ')
    {
        s++;
    }

    int flag = 1;
    if (*s == '-')
    {
        flag = -1;
        s++;
    }
    else if (*s == '+')
    {
        flag = 1;
        s++;
    }
    long ret = 0;
    while (*s != '\0')
    {
        if (isdigit(*s) != 0)
        {
            ret = ret * 10 + flag * (*s - '0');
            s++;
            if (ret > INT_MAX)
            {
                return INT_MAX;
            }
            else if (ret < INT_MIN)
            {
                return INT_MIN;
            }
        }
        else
        {
            break;
        }

    }
    return (int)ret;
}

int main()
{

    char ch[] = "   -12  34";
    int n = myAtoi(ch);
    printf("%d\n", n);
    return 0;
}