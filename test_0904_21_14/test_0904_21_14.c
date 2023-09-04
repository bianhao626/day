#include <stdio.h>

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个 n 级的台阶总共有多少种跳法(先后次序不同算不同的结果)。
经典的斐波那契数列
*/
//int jumpFloor(int number)
//{
//    int arr[40] = { 0 };
//    arr[0] = 1;
//    arr[1] = 2;
//    for (int i = 2; i < number; i++)
//    {
//        arr[i] = arr[i - 1] + arr[i - 2];
//    }
//    return arr[number - 1];
//}

int jumpFloor(int number)
{
	//递归的写法
	if (number == 1 || number == 2)
	{
		return number;
	}
	return jumpFloor(number - 1) + jumpFloor(number - 2);
}
int main()
{
	int ret = jumpFloor(7);
	printf("%d", ret);
	return 0;
}