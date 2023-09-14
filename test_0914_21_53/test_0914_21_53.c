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
//主函数
char* trans(char* s, int n) {
    //翻转整个字符串
    reverse(s, 0, n - 1);
    int i = 0, j = 0;
    while (i < n) {
        j = i;
        //按照空格分段进行大小写切换，部分反转
        while (j < n && s[j] != ' ') {
            //切换大小写
            if (s[j] >= 'A' && s[j] <= 'Z') {
                s[j] += 32;
            }
            else if (s[j] >= 'a' && s[j] <= 'z') {
                s[j] -= 32;
            }
            j++;
        }
        //把这一段翻转
        reverse(s, i, j - 1);
        i = j + 1;//i变为空格后一个
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