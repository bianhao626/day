#include "contact.h"


void menu()
{
	printf("1.add\n");
	printf("2.delete\n");
	printf("3.find\n");
	printf("4.modify\n");
	printf("5.show\n");
	printf("6.clear\n");
	printf("7.sort\n");
	printf("0.exit\n");
}
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MOD,
	SHOW,
	CLE,
	SORT,
};

int main()
{
	int input = 0;
	//创建信息
	con c;
	InitContact(&c);

	do
	{
		menu();
		printf("请输入您的选择>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&c);
			break;
		case DEL:
			DelContact(&c);
			break;
		case SEARCH:
			SearchContact(&c);
			break;
		case MOD:
			ModContact(&c);
			break;
		case SHOW:
			ShowContact(&c);
			break;
		case CLE:
			CleContact(&c);
			break;
		case SORT:
			SortContact(&c);
			break;
		case EXIT:
			DestroyContact(&c);
			printf("已退出！\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}
	} while (input);
	return 0;
}