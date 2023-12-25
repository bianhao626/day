#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IPv4 "IPv4"
#define IPv6 "IPv6"
#define No "Neither"

char* solve(char* IP)
{
    int len_4 = 1;
    int len_6 = 1;
    for (int i = 0; i < strlen(IP); i++)
    {
        if (IP[i] == '.')
        {
            len_4++;
        }
        if (IP[i] == ':')
        {
            len_6++;
        }
    }

    //先判断字符串的长度符合要求
    if (len_4 == 4)
    {
        //IPv4的规则
        char* token;
        token = strtok(IP, ".");

        while (token != NULL)
        {
            if (!token)
            {
                break;
            }
            len_4--;
            if (atoi(token) < 0 || 
                atoi(token) > 255 || 
                token[0] == '0' || 
                (atoi(token) < (int)pow(10, strlen(token) - 1)))
            {
                return No;
            }
            token = strtok(NULL, ".");
        }
        if (len_4 == 0)
        {
            return IPv4;
        }
        else
        {
            return No;
        }
    }
    else if (len_6 == 8)
    {
        char* token;
        token = strtok(IP, ":");

        while (token != NULL)
        {
            if (!token)
            {
                break;
            }
            len_6--;
            if (strlen(token) > 4 || 
                (token[0] == '0' && token[1] == '0'))
            {
                return No;
            }
            else
            {
                for (int j = 0; j < strlen(token); j++)
                {
                    int data = (int)token[j];
                    if ((data > 0x46 && data < 0x61) || (data > 0x72))
                        return No;
                }
            }
            token = strtok(NULL, ":");
        }
        if (len_6 == 0)
        {
            return IPv6;
        }
        else
        {
            return No;
        }
    }

    return No;
}


int main()
{
	char* str = "001";
	int str_int = atoi(str);
    printf("%d\n", str_int);
	return 0;
}