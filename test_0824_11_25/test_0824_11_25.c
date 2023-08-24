#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int findRound(const char* src, char* find)
//{
//	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
//	strcpy(tmp, src); //先拷贝一遍
//	strcat(tmp, src); //再连接一遍
//	return strstr(tmp, find) != NULL; //看看找不找得到
//}
//int main()
//{
//	char ch1[] = "ABCDEF";
//	char ch2[] = "CDEFAD";
//	int ret = findRound(ch1, ch2);
//	printf("%d", ret);
//	return 0;
//}

/*实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB*/

//1.一般思路
//void leftRound(char* src, int time)
//{
//	int i, j, tmp;
//	int len = strlen(src);
//	time %= len; //长度为5的情况下，旋转6、11、16...次相当于1次，7、12、17...次相当于2次，以此类推。
//	for (i = 0; i < time; i++) //执行k次的单次平移
//	{
//		tmp = src[0];
//		for (j = 0; j < len - 1; j++) //单次平移
//		{
//			src[j] = src[j + 1];
//		}
//		src[j] = tmp;
//	}
//}

//2.改进一
//void leftRound(char* src, int time)
//{
//	int len = strlen(src);
//	int pos = time % len; //断开位置的下标
//	char tmp[256] = { 0 }; //更准确的话可以选择malloc len + 1个字节的空间来做这个tmp
//
//	strcpy(tmp, src + pos); //先将后面的全部拷过来
//	strncat(tmp, src, pos); //然后将前面几个接上
//	strcpy(src, tmp); //最后拷回去
//}

//3.改进三
void reverse(char* src, int start, int end)
{
	int i, j;
	char tmp;
	for (i = start, j = end; i < j; i++, j--)
	{
		tmp = src[i];
		src[i] = src[j];
		src[j] = tmp;
	}
}
void leftRound(char* src, int time)
{
	int len = strlen(src);
	int pos = time % len;
	reverse(src, 0, pos - 1);
	reverse(src, pos, len - 1);
	reverse(src, 0, len - 1);
}
int main()
{
	char ch1[] = "ABCDEF";
	leftRound(ch1, 2);
	printf("%s", ch1);
	return 0;
}