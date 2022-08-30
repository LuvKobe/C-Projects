#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"


/*
通讯录的实现要求：
1. 可以存放1000个用户的信息
2. 用户的信息包括：姓名、年龄、性别、电话、住址
3. 增加联系人
4. 删除联系人
5. 查找联系人
6. 修改联系人
7. 排序（年龄 / 名字）
8. 查看联系人
*/

enum Option
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

void menu()
{
	//system("cls"); //清空屏幕
	printf("\n");
	printf("\t\t ----------------通讯录管理系统--------------\n");
	printf("\t\t︱\t\t 1 添加联系人               ︱\n");
	printf("\t\t︱\t\t 2 删除联系人               ︱\n");
	printf("\t\t︱\t\t 3 查找联系人               ︱\n");
	printf("\t\t︱\t\t 4 修改联系人               ︱\n");
	printf("\t\t︱\t\t 5 排序联系人               ︱\n");
	printf("\t\t︱\t\t 6 查看通讯录               ︱\n");
	printf("\t\t︱\t\t 0 退出通讯录               ︱\n");
	printf("\t\t --------------------------------------------\n");
	printf("\t\t请选择(0-6):> ");
}

int main()
{
	int input = 0;
	Contact con; //通讯录

	InitContact(&con);

	do
	{
		menu(); // 打印菜单
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DELETE:
			DeleteContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			// 保存信息到文件
			SaveContact(&con);
			// 当退出通讯录的时候，把malloc开辟的空间销毁
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误,请重新输入\n");
			break;
		}
	} while (input);
}


