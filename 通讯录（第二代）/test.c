#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

/*
ͨѶ¼��ʵ��Ҫ��
1. ���Դ��1000���û�����Ϣ
2. �û�����Ϣ���������������䡢�Ա𡢵绰��סַ
3. ������ϵ��
4. ɾ����ϵ��
5. ������ϵ��
6. �޸���ϵ��
7. �������� / ���֣�
8. �鿴��ϵ��
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

// ���İ�˵�
void menu1()
{
	printf("+----------------------------------+\n");
	printf("|               ͨѶ¼             |\n");
	printf("|----------------------------------|\n");
	printf("|   1.������ϵ��     2.ɾ����ϵ��  |\n");
	printf("|   3.������ϵ��     4.�޸���ϵ��  |\n");
	printf("|   5.������ϵ��     6.�鿴��ϵ��  |\n");
	printf("|          0.�˳�ͨѶ¼            |\n");
	printf("|----------------------------------|\n");
	printf("|                     ����by Edison|\n");
	printf("+----------------------------------+\n");

}

// Ӣ�İ�˵�
void menu2()
{
	printf("+-----------------------+\n");
	printf("|        contact        |\n");
	printf("|   1.Add     2.Delete  |\n");
	printf("|   3.Search  4.Modify  |\n");
	printf("|   5.Sort    6.Show    |\n");
	printf("|        0.Exit         |\n");
	printf("+-----------------------+\n");
}

int main()
{
	int input = 0;
	Contact con; //ͨѶ¼

	InitContact(&con);

	do
	{
		menu1(); // ��ӡ�˵�
		printf("��ѡ��:> ");
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
			// ���˳�ͨѶ¼��ʱ�򣬰�malloc���ٵĿռ�����
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����,����������\n");
			break;
		}
	} while (input);
}