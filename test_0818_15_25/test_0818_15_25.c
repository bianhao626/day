#include <stdio.h>

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
////�ṹ���ַ����
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s);  //���ṹ��
//	print2(&s); //����ַ
//	return 0;
//}struct Stu
{
    char name[20];
    int age;
};void print(struct Stu* ps)
{
    printf("name = %s   age = %d\n", (*ps).name, (*ps).age);
    //ʹ�ýṹ��ָ�����ָ�����ĳ�Ա
    printf("name = %s   age = %d\n", ps->name, ps->age);
}
int main()
{
    struct Stu s = { "zhangsan", 20 };
    print(&s);//�ṹ���ַ����
    return 0;
}