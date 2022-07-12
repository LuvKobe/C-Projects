#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(Contact* pc) {
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data)); // 把pc里面的data数组的内容初始化为0
}

// 1.添加一个联系人的信息
void AddContact(Contact* pc) {
	assert(pc);

	// 通讯录存满了
	if (pc->sz == MAX) {
		printf("通讯录存储内存不够，无法添加\n");
		return;
	}

	// 输入联系人
	// data是用户数组，需要下标，但是数组的下标是从0开始的，我们定义的sz刚好是0，所以data里面直接放pc指向的sz
	printf("请输入名字:> ");
	scanf("%s", pc->data[pc->sz].name); //name本身是数组名，这里不需要取地址

	printf("请输入年龄:> ");
	scanf("%d", &pc->data[pc->sz].age);

	printf("请输入性别:> ");
	scanf("%s", pc->data[pc->sz].sex);

	printf("请输入电话:> ");
	scanf("%s", pc->data[pc->sz].tele);

	printf("请输入地址:> ");
	scanf("%s", pc->data[pc->sz].addr);

	// sz代表data数组里面用户的个数，所以当添加完一个人的信息以后，sz就加1，指向下一个位置
	pc->sz++;
	printf("增加联系人成功\n");
}

// 通过名字查找联系人，找到了返回下标，没找到返回-1
int FindByName(const Contact* pc, char name[]) {
	int i = 0;
	for (i = 0; i < pc->sz; ++i) {
		if (0 == strcmp(pc->data[i].name, name)) {
			return i; // 找到了返回下标
		}
	}
	return -1; //找不到的情况
}

// 2.删除一个联系人的信息
void DeleteContact(Contact* pc) {
	assert(pc);
	char name[MAX_NAME] = { 0 };
	if (0 == pc->sz) {
		printf("通讯录为空，无法删除\n");
		return; // 直接返回
	}
	printf("请输入要删除联系人的姓名:> ");
	scanf("%s", name);

	//查找指定联系人
	//在pc指向的通讯录里面，查名字为name的联系人
	int pos = FindByName(pc, name);  //找到了返回下标，没找到返回-1
	if (-1 == pos) {
		printf("查无此人\n");
	}
	else //找到了就删除
	{
		int j = 0;
		for (j = pos; j < (pc->sz)-1; ++j) {
			pc->data[j] = pc->data[j + 1]; //从要删除的联系人位置开始，后一位联系人信息覆盖前一个联系人信息
		}
		pc->sz--; //通讯录中联系人个数-1
		printf("删除指定联系人成功\n");
	}
}

// 3.查找指定联系人并打印其信息
void SearchContact(const Contact* pc) {
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的联系人姓名:> ");
	scanf("%s", &name);
	int pos = FindByName(pc, name);

	if (-1 == pos) {
		printf("对不起，查无此人\n");
		return;
	}
	else {
		printf("查找成功\n");
		printf("%-4s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-4s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr
		);
	}
}

// 4.修改一个联系人的信息
void ModifyContact(Contact* pc) {
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的联系人姓名:> ");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (-1 == pos) {
		printf("没有该联系人的信息\n");
	}
	else
	{
		printf("请问你要修改这个联系人的什么信息？\n");
		printf("1.姓名 2.年龄 3.性别 4.电话 5.地址\n");
		int n = 0;
		printf("请选择:> ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("请重新输入姓名:> ");
			scanf("%s", pc->data[pos].name);
			printf("修改成功\n");
			break;
		case 2:
			printf("请重新输入年龄:> ");
			scanf("%d", &pc->data[pos].age);
			printf("修改成功\n");
			break;
		case 3:
			printf("请重新输入性别:> ");
			scanf("%s", pc->data[pos].sex);
			printf("修改成功\n");
			break;
		case 4:
			printf("请重新输入电话:> ");
			scanf("%s", pc->data[pos].tele);
			printf("修改成功\n");
			break;
		case 5:
			printf("请重新输入地址:> ");
			scanf("%s", pc->data[pos].addr);
			printf("修改成功\n");
			break;
		}
	}

}

// 按照姓名排序
int CmpByName(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

// 按照年龄排序
int CmpByAge(const void* e1, const void* e2) {
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}


// 5.对通讯录里联系人进行排序
void SortContact(Contact* pc) {
	assert(pc);
	printf("请问你要以什么样的方式对通讯录的联系人进行排序？\n");
	printf("1.姓名  2.年龄\n");
	int n = 0;
	printf("请选择:> ");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), CmpByName);//姓名排序
		ShowContact(pc);
		break;
	case 2:
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), CmpByAge);//年龄排序
		ShowContact(pc);
		break;
	}
}


// 6.Show
void ShowContact(const Contact* pc) {
	assert(pc);
	if (0 == pc->sz) {
		printf("通讯录为空\n");
		return;
	}
	else
	{
		//打印信息栏
		printf("%-4s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		int i = 0;
		for (i = 0; i < pc->sz; ++i) {
			printf("%-4s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr
			);
		}
	}

}



