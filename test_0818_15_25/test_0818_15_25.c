#include <stdio.h>

//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4}, 1000 };
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s);  //传结构体
//	print2(&s); //传地址
//	return 0;
//}struct Stu
{
    char name[20];
    int age;
};void print(struct Stu* ps)
{
    printf("name = %s   age = %d\n", (*ps).name, (*ps).age);
    //使用结构体指针访问指向对象的成员
    printf("name = %s   age = %d\n", ps->name, ps->age);
}
int main()
{
    struct Stu s = { "zhangsan", 20 };
    print(&s);//结构体地址传参
    return 0;
}