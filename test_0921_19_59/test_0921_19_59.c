#include <stdio.h>
#include <stdlib.h>
//int duplicate(int* numbers, int numbersLen)
//{
//    //��ϣ���鷽��ʱ�临�Ӷ���n,�ռ临�Ӷ���n
//    int* ret = (int*)malloc(sizeof(int) * numbersLen);
//    for (int i = 0; i < numbersLen; i++)
//    {
//        //��ʼ��
//        ret[i] = 0;
//    }
//    if (numbersLen == 0 || numbersLen == -1)
//    {
//        return -1;
//    }
//    for (int i = 0; i < numbersLen; i++)
//    {
//
//        ret[*numbers++] += 1;
//    }
//    for (int i = 0; i < numbersLen; i++)
//    {
//        if (ret[i] >= 2)
//        {
//            return i;
//        }
//    }
//    return -1;
//}

int duplicate(int* numbers, int numbersLen)
{
    //ʱ�任�ռ�ķ�ʽʱ�临�Ӷ�n^2,�ռ临�Ӷ���1
    for (size_t i = 0; i < numbersLen; i++)
    {
        for (size_t j = i+1; j < numbersLen; j++)
        {
            if (numbers[i] == numbers[j])
            {
                return numbers[i];
            }
        }
    }
    return -1;
}
int main()
{
    int numbers[7] = { 2,3,1,0,2,5,3 };
    int ret = duplicate(numbers, 7);
    printf("%d", ret);
    return 0;
}