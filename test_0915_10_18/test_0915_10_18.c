#include <stdio.h>
//char* longestCommonPrefix(char** strs, int strsLen)
//{
//    if (strsLen == 0)
//    {
//        return strs;
//    }
//    int i = 0, j = 0;
//    char tmp = strs[0][i];
//    while (tmp)
//    {
//        for (j = 0; j < strsLen; j++)
//        {
//            if (strs[j][i] != tmp)
//            {
//                break;
//            }
//        }
//        if (j < strsLen)
//        {
//            break;
//        }
//        tmp = strs[0][++i];
//    }
//    strs[0][i] = '\0';
//    return strs[0];
//}

int main()
{
	int a[3][4] = { 0 };
	//��ά����Ĵ�С
	printf("%d\n", sizeof(a));
	//48
	printf("%d\n", sizeof(a[0][0]));
	//4  ����Ԫ�صĴ�С
	printf("%d\n", sizeof(a[0]));
	//16  �൱��һά����������������Լ����������һά����Ĵ�С
	printf("%d\n", sizeof(a[0] + 1));
	//8  ��ʱ�൱����64λ��ַ�µ�һ��ָ��
	printf("%d\n", sizeof(*(a[0] + 1)));
	//4
	printf("%d\n", sizeof(a + 1));
	//8
	printf("%d\n", sizeof(*(a + 1)));
	//16 �൱��һά����������������Լ����������һά����Ĵ�С
	printf("%d\n", sizeof(&a[0] + 1));
	//8
	printf("%d\n", sizeof(*(&a[0] + 1)));
	//16
	printf("%d\n", sizeof(*a));
	//16
	printf("%d\n", sizeof(a[3]));
	//16
	return 0;
}