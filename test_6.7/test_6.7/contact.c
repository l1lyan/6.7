#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(Contact* pc)
{
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("请输入姓名：>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄：>");
	scanf("%d", &pc->data[pc->count].age);//取地址符
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话：>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入住址：>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("增加成功\n");
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",  pc->data[i].name, 
												pc->data[i].age, pc->data[i].sex, 
												pc->data[i].tele, pc->data[i].addr);
	}
}

int FindName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	char name[MAX_NAME];
	printf("请输入要删除人的名字：>");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("通讯录中不存在此人\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要查找人的名字：>");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("通讯录中不存在此人\n");
		return;
	}
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "姓名", "年龄", "性别", "电话", "住址");
	printf("%20s\t%5d\t%5s\t%12s\t%30s\n", pc->data[pos].name,
			pc->data[pos].age, pc->data[pos].sex,
			pc->data[pos].tele, pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要修改人的名字：>");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("通讯录中不存在此人\n");
		return;
	}
	printf("请输入姓名：>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄：>");
	scanf("%d", &pc->data[pos].age);//取地址符
	printf("请输入性别：>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话：>");
	scanf("%s", pc->data[pos].tele);
	printf("请输入住址：>");
	scanf("%s", pc->data[pos].addr);
}
int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功\n");
}