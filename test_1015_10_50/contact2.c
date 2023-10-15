#include "contact2.h"
void CheckCapacity(con* c);

//void InitContact(con* c)
//{
//	assert(c);
//	c->sz = 0;
//	memset(c->data, 0, sizeof(c->data));
//}

void LoadContact(con* c)
{
	FILE* pf = fopen("contact2.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return 1;
	}

	peo tmp = { 0 };
	while (fread(&tmp, sizeof(peo), 1, pf))
	{
		CheckCapacity(c);
		c->data[c->sz] = tmp;
		c->sz++;
	}
	fclose(pf);
	pf = NULL;
}
void InitContact(con* c)
{
	assert(c);
	c->sz = 0;
	c->capacity = 3;
	c->data = calloc(c->capacity, sizeof(peo));
	if (c->data == NULL)
	{
		perror("InitContact--calloc");
		return;
	}
	//加载文件中的信息到显示上
	LoadContact(c);
}
//void DestroyContact(con* c)
//{
//	free(c->data);
//	c->data = NULL;
//	c->capacity = 0;
//	c->sz = 0;
//}
//void AddContact(con* c)
//{
//	assert(c);
//	if (c->sz == 1000)
//	{
//		printf("通讯录已满！\n");
//	}
//	printf("请输入名字>");
//	scanf("%s", c->data[c->sz].name);
//	printf("请输入年龄>");
//	scanf("%d", &(c->data[c->sz].age));
//	printf("请输入性别>");
//	scanf("%s", c->data[c->sz].sex);
//	printf("请输入电话>");
//	scanf("%s", c->data[c->sz].tele);
//	printf("请输入住址>");
//	scanf("%s", c->data[c->sz].addr);
//	c->sz++;
//	printf("添加成功！\n");
//}
void CheckCapacity(con* c)
{
	if (c->sz == c->capacity)
	{
		peo* p = (peo*)realloc(c->data, (c->capacity + 2) * sizeof(peo));
		if (p != NULL)
		{
			c->data = p;
			c->capacity += 2;
			printf("扩容成功！\n");
		}
		else
		{
			perror("AddContact--realloc");
			return;
		}
	}
}
void AddContact(con* c)
{
	assert(c);
	CheckCapacity(c);
	printf("请输入名字>");
	scanf("%s", c->data[c->sz].name);
	printf("请输入年龄>");
	scanf("%d", &(c->data[c->sz].age));
	printf("请输入性别>");
	scanf("%s", c->data[c->sz].sex);
	printf("请输入电话>");
	scanf("%s", c->data[c->sz].tele);
	printf("请输入住址>");
	scanf("%s", c->data[c->sz].addr);
	c->sz++;
	printf("添加成功！\n");
}
void ShowContact(con* c)
{
	assert(c);
	if (c->sz == 0)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("%-10s %-5s %-5s %-12s %-30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (size_t i = 0; i < c->sz; i++)
	{
		printf("%-10s %-5d %-5s %-12s %-30s\n",
			c->data[i].name, c->data[i].age, c->data[i].sex, c->data[i].tele, c->data[i].addr);
	}
}

int FindName(con* c, char name[])
{
	assert(c);
	for (size_t i = 0; i < c->sz; i++)
	{
		if (strcmp(c->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(con* c)
{
	char name[20];
	assert(c);
	if (c->sz == 0)
	{
		printf("通讯录为空，无法删除！\n");
		return;
	}
	printf("请输入要删除的人的名字>");
	scanf("%s", name);
	//先找
	int ret = FindName(c, name);
	if (ret == -1)
	{
		printf("查无此人！\n");
		return;
	}
	//再删除
	for (size_t i = ret; i < c->sz - 1; i++)
	{
		c->data[i] = c->data[i + 1];
	}
	c->sz--;
	printf("删除成功！\n");
}
void SearchContact(con* c)
{
	char name[20];
	assert(c);
	printf("请输入要查找的名字>");
	scanf("%s", name);
	int ret = FindName(c, name);
	if (ret == -1)
	{
		printf("查无此人！\n");
		return;
	}
	printf("%-10s %-5s %-5s %-12s %-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-10s %-5d %-5s %-12s %-30s\n",
		c->data[ret].name, c->data[ret].age, c->data[ret].sex, c->data[ret].tele, c->data[ret].addr);
}
void ModContact(con* c)
{
	char name[20];
	assert(c);
	printf("请输入要修改信息的人的名字>");
	scanf("%s", name);
	int ret = FindName(c, name);
	if (ret == -1)
	{
		printf("查无此人！\n");
		return;
	}
	printf("请输入名字>");
	scanf("%s", c->data[ret].name);
	printf("请输入年龄>");
	scanf("%d", &(c->data[ret].age));
	printf("请输入性别>");
	scanf("%s", c->data[ret].sex);
	printf("请输入电话>");
	scanf("%s", c->data[ret].tele);
	printf("请输入住址>");
	scanf("%s", c->data[ret].addr);
	printf("修改成功！\n");
}
void CleContact(con* c)
{
	assert(c);
	InitContact(c);
	printf("已清空！\n");
}
int cmp(const void* e1, const void* e2)
{
	return strcmp(((peo*)e1)->name, ((peo*)e2)->name);
}
void SortContact(con* c)
{
	assert(c);
	qsort(c->data, c->sz, sizeof(c->data[0]), cmp);
	printf("排序完成！\n");
	ShowContact(c);
}
void SaveContact(con* c)
{
	FILE* pf = fopen("contact2.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return 1;
	}

	for (size_t i = 0; i < c->sz; i++)
	{
		fwrite(&(c->data[i]), sizeof(peo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}