#include <stdio.h>
#include <string.h>

void reverse(char* s, int head, int tail) {
    char temp;
    while (head < tail) {
        temp = s[head];
        s[head] = s[tail];
        s[tail] = temp;
        head++;
        tail--;
    }
}
//������
char* trans(char* s, int n) {
    //��ת�����ַ���
    reverse(s, 0, n - 1);
    int i = 0, j = 0;
    while (i < n) {
        j = i;
        //���տո�ֶν��д�Сд�л������ַ�ת
        while (j < n && s[j] != ' ') {
            //�л���Сд
            if (s[j] >= 'A' && s[j] <= 'Z') {
                s[j] += 32;
            }
            else if (s[j] >= 'a' && s[j] <= 'z') {
                s[j] -= 32;
            }
            j++;
        }
        //����һ�η�ת
        reverse(s, i, j - 1);
        i = j + 1;//i��Ϊ�ո��һ��
    }
    return s;
}
int main()
{
	char* s = "Hello World";
	int n = strlen(s);
	char* ss = trans(s, n);
	printf("%s", ss);
	return 0;
}