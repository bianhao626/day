#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//������ 16.05. �׳�β��
int trailingZeroes(int n)
{
    //����������ͳ�ƣ����ڷ�����ѧ�ķ���
    int ans = 0;
    while (n)
    {
        n /= 5;
        ans += n;
    }
    return ans;
}

//int main()
//{
//    int n = 25;
//    int ret = trailingZeroes(n);
//    printf("%d\n", ret);
//    return 0;
//}

//HJ7 ȡ����ֵ
int main()
{
    float f = 0;
    scanf("%f", &f);

    printf("%d", (int)(f + 0.5));
    //ȡ�����㣬һ����ڸ�������˵��ֻ������������
    return 0;
}