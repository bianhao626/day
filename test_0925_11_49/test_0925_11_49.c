#include <stdio.h>
/*
* ���ڽṹ�壬�ص�����һ�½ṹ��Ĵ�С
* ������������ӣ�չ���Ľ���һ�½ṹ��Ĵ�С
*/
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//
//	return 0;
//}
/*
���ȵ����սṹ��Ķ������
1. ��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ����
2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ����VS��Ĭ�ϵ�ֵΪ8��
3. �ṹ���ܴ�СΪ����������ÿ����Ա��������һ��������������������
4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ�����
���С��������������������Ƕ�׽ṹ��Ķ�����������������
*/
/*
* �ڴ������ʲô�ô��أ�
* 1����ֲԭ����ЩӲ��ֻ����ȡĳЩ��ַ��������
* 2������ԭ����ʱ��δ��������ݷ��ʴ�������Ҫ�������Σ���������ݣ���ֻ��Ҫ����һ�δ���
*/

//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4}, 1000 };
////�ṹ�崫��
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
//�ṹ���ַ����
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s);  //���ṹ��
//	print2(&s); //����ַ
//	return 0;
//}
/*
�������ε�ʱ�򣬲�������Ҫѹջ������ʱ��Ϳռ��ϵ�ϵͳ������
�������һ���ṹ������ʱ�򣬽ṹ����󣬲���ѹջ�ĵ�ϵͳ�����Ƚϴ����Իᵼ�����ܵ�
�½���
*/


//λ��
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	return 0;
//}
/*
* λ���ǰ��ձ���λ�ķ�ʽ���ٿռ��
* ����͵��÷����ǣ������е�ipЭ�����ݰ��ĸ�ʽ
*/


//ö�ٳ�������˼����ö�������Ľṹ��һ������
//enum Color//��ɫ
//{
//	RED = 1,
//	GREEN = 2,
//	BLUE = 4
//};
//int main()
//{
//	enum Color co = BLUE;
//	//ö���൱�����Ż����define
//	//���ƾ��Ǳ��ڵ���
//}


// ���ϣ������壩:�������Ͷ���ı���Ҳ����һϵ�еĳ�Ա����������Щ��Ա����ͬһ��ռ䣨��������Ҳ�й����壩
//ͬһʱ��ֻ����ʹ�����е�һ��������������Ĵ�С�ǳ�Ա�����ĳ�Ա�Ĵ�С
//union Un
//{
//	char a;
//	int i;
//};
//int main()
//{
//	union Un un;
//	
//	printf("%p\n", &un);
//	printf("%p\n", &(un.a));
//	printf("%p\n", &(un.i));
//	return 0;
//}
/*
����������һ���÷������жϲ���ϵͳ�洢�Ǵ�˴洢����С�˴洢
*/
int check()
{
	union 
	{
		char c;
		int i;
	}un;
	un.i = 1;
	return un.c;
}
int main()
{
	int ret = check();
	if (ret == 1)
	{
		printf("С��");
	}
	else
	{
		printf("���");
	}
	return 0;
}

//typedef struct {
//	int a;//4
//	char b;//1
//	short c;//2
//	short d;//2
//}AA_t;
//int main()
//{
//	printf("%zd", sizeof(AA_t));
//	return 0;
//}

//#pragma pack(4)/*����ѡ���ʾ4�ֽڶ��� ƽ̨��VS2013�����ԣ�C����*/
////����long ��4���ֽ�
//int main(int argc, char* argv[])
//{
//    struct tagTest1
//    {
//        short a;
//        char d;
//        long b;
//        long c;
//    };
//    struct tagTest2
//    {
//        long b;
//        short c;
//        char d;
//        long a;
//    };
//    struct tagTest3
//    {
//        short c;
//        long b;
//        char d;
//        long a;
//    };
//    struct tagTest1 stT1;
//    struct tagTest2 stT2;
//    struct tagTest3 stT3;
//
//    printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//    return 0;
//}
//#pragma pack()

//int main()
//{
//    union
//    {
//        short k;
//        char i[2];
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf("%x\n", a.k);
//    return 0;
//}

//int main()
//{
//    unsigned char puc[4];
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    return 0;
//}