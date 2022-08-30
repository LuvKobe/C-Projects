#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"


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

void menu()
{
	//system("cls"); //�����Ļ
	printf("\n");
	printf("\t\t ----------------ͨѶ¼����ϵͳ--------------\n");
	printf("\t\t��\t\t 1 �����ϵ��               ��\n");
	printf("\t\t��\t\t 2 ɾ����ϵ��               ��\n");
	printf("\t\t��\t\t 3 ������ϵ��               ��\n");
	printf("\t\t��\t\t 4 �޸���ϵ��               ��\n");
	printf("\t\t��\t\t 5 ������ϵ��               ��\n");
	printf("\t\t��\t\t 6 �鿴ͨѶ¼               ��\n");
	printf("\t\t��\t\t 0 �˳�ͨѶ¼               ��\n");
	printf("\t\t --------------------------------------------\n");
	printf("\t\t��ѡ��(0-6):> ");
}

int main()
{
	int input = 0;
	Contact con; //ͨѶ¼

	InitContact(&con);

	do
	{
		menu(); // ��ӡ�˵�
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
			// ������Ϣ���ļ�
			SaveContact(&con);
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


