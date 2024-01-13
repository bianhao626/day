#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//面试题 16.05. 阶乘尾数
int trailingZeroes(int n)
{
    //质数的数量统计，属于分析数学的范畴
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

//HJ7 取近似值
int main()
{
    float f = 0;
    scanf("%f", &f);

    printf("%d", (int)(f + 0.5));
    //取整运算，一般对于浮点数来说是只保留整数部分
    return 0;
}