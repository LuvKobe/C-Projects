#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//�˵�����
void menu()
{
	printf("*********************\n");
	printf("*******1. Play*******\n");
	printf("*******0. Exit*******\n");
	printf("*********************\n");

}

//��Ϸʵ�ֺ���
void game()
{
	int guess = 0;
	int r = rand() % 100 + 1; //�����ֵķ�Χ��1 ~ 100
	while (1)
	{
		printf("�������(1~100):> ");
		scanf("%d", &guess);
		if (guess == r) {
			printf("��ϲ��,�¶���\n");
			break;
		}
		else if (guess > r) {
			printf("�´���\n");
		}
		else {
			printf("��С��\n");
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL)); //���������
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("�������,����������\n");
			break;
		}
	} while (input);
	return 0;
}