#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int findRound(const char* src, char* find)
//{
//	char tmp[256] = { 0 }; //��һ�������ռ佫ԭ�ַ�����������ԭ�ַ���
//	strcpy(tmp, src); //�ȿ���һ��
//	strcat(tmp, src); //������һ��
//	return strstr(tmp, find) != NULL; //�����Ҳ��ҵõ�
//}
//int main()
//{
//	char ch1[] = "ABCDEF";
//	char ch2[] = "CDEFAD";
//	int ret = findRound(ch1, ch2);
//	printf("%d", ret);
//	return 0;
//}

/*ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB*/

//1.һ��˼·
//void leftRound(char* src, int time)
//{
//	int i, j, tmp;
//	int len = strlen(src);
//	time %= len; //����Ϊ5������£���ת6��11��16...���൱��1�Σ�7��12��17...���൱��2�Σ��Դ����ơ�
//	for (i = 0; i < time; i++) //ִ��k�εĵ���ƽ��
//	{
//		tmp = src[0];
//		for (j = 0; j < len - 1; j++) //����ƽ��
//		{
//			src[j] = src[j + 1];
//		}
//		src[j] = tmp;
//	}
//}

//2.�Ľ�һ
//void leftRound(char* src, int time)
//{
//	int len = strlen(src);
//	int pos = time % len; //�Ͽ�λ�õ��±�
//	char tmp[256] = { 0 }; //��׼ȷ�Ļ�����ѡ��malloc len + 1���ֽڵĿռ��������tmp
//
//	strcpy(tmp, src + pos); //�Ƚ������ȫ��������
//	strncat(tmp, src, pos); //Ȼ��ǰ�漸������
//	strcpy(src, tmp); //��󿽻�ȥ
//}

//3.�Ľ���
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