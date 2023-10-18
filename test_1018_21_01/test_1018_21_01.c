#include <stdio.h>

//int main() {
//    int n;
//    scanf("%d", &n);
//
//    char ch[14] = { 0 };
//    int  i = 0, k = 0;
//    while (n)
//    {
//        if (k != 0 && k % 3 == 0)
//        {
//            ch[i++] = ',';
//        }
//        ch[i] = n % 10 + '0';
//        i++;
//        k++;
//        n = n / 10;
//    }
//    i--;
//    for (i; i >= 0; i--)
//    {
//        printf("%c", ch[i]);
//    }
//    return 0;
//}

#include <stdio.h>
#include <string.h>

int main()
{
    char arr1[101];
    char arr2[101];
    gets(arr1);
    gets(arr2);

    int i = 0;
    while (arr1[i])
    {
        if (strchr(arr2, arr1[i]) == NULL)
        {
            printf("%c", arr1[i]);
        }
        i++;
    }
    return 0;
}