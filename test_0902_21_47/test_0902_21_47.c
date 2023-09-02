#include <stdio.h>

//int Fibonacci(int n)
//{
//    //��ͳ�ݹ�ķ���������ʱ��Ч����
//    if (n == 1 || n == 2)
//    {
//        return 1;
//    }
//    else
//    {
//        return Fibonacci(n - 1) + Fibonacci(n - 2);
//    }
//}

//int f[50] = { 0 };
//int Fibonacci(int n)
//{
//    //�����ظ��ļ��㣬����ʹʱ�临�ӶȽ��͵�n
//    if (n == 1 || n == 2)
//    {
//        return 1;
//    }
//    if (f[n] > 0)
//    {
//        return f[n];
//    }
//    return f[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
//}

int f[50] = { 0 };
int Fibonacci(int n)
{
    //��̬�滮�ķ�ʽ
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
int main()
{
    int n = 6;
    int ret = Fibonacci(n);
    printf("%d", ret);
    return 0;
}