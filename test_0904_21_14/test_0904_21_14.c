#include <stdio.h>

/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ�� n ����̨���ܹ��ж���������(�Ⱥ����ͬ�㲻ͬ�Ľ��)��
�����쳲���������
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
	//�ݹ��д��
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