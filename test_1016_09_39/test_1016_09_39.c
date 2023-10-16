#include <stdio.h>

//#define ADD(x,y) ((x)+(y))
//int main()
//{
//	int a = 1;
//	int b = 21;
//	printf("%d", ADD(a, b));
//	return 0;
//}

//#include <stddef.h>
//
//#define MY_OFFSETOF(a,b) (size_t)&(((a*)0)->b)
////&(((a*)0)->b)È¡³öµØÖ·
//typedef struct S
//{
//	char c1;
//	int a;
//	char c2;
//}s;
//int main()
//{
//	s t;
//	//printf("%zd\n", offsetof(s, c1));
//	//printf("%zd\n", offsetof(s, a));
//	//printf("%zd\n", offsetof(s, c2));
//
//	printf("%zd\n", MY_OFFSETOF(s, c2));
//	printf("%zd\n", MY_OFFSETOF(s, c1));
//	printf("%zd\n", MY_OFFSETOF(s, a));
//
//	return 0;
//}

#define EXCHANGE(n) (n=((n&0x55555555)<<1)+((n&0xaaaaaaaa)>>1))
int main()
{
	int a = 11;
	EXCHANGE(a);
	printf("%d\n", a);
	return 0;
}