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
	//二维数组的大小
	printf("%d\n", sizeof(a));
	//48
	printf("%d\n", sizeof(a[0][0]));
	//4  单个元素的大小
	printf("%d\n", sizeof(a[0]));
	//16  相当于一维数组的数组名，所以计算的是整个一维数组的大小
	printf("%d\n", sizeof(a[0] + 1));
	//8  此时相当于是64位地址下的一个指针
	printf("%d\n", sizeof(*(a[0] + 1)));
	//4
	printf("%d\n", sizeof(a + 1));
	//8
	printf("%d\n", sizeof(*(a + 1)));
	//16 相当于一维数组的数组名，所以计算的是整个一维数组的大小
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