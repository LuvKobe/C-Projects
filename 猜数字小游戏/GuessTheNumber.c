#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//菜单函数
void menu()
{
	printf("*********************\n");
	printf("*******1. Play*******\n");
	printf("*******0. Exit*******\n");
	printf("*********************\n");

}

//游戏实现函数
void game()
{
	int guess = 0;
	int r = rand() % 100 + 1; //猜数字的范围：1 ~ 100
	while (1)
	{
		printf("请猜数字(1~100):> ");
		scanf("%d", &guess);
		if (guess == r) {
			printf("恭喜你,猜对了\n");
			break;
		}
		else if (guess > r) {
			printf("猜大了\n");
		}
		else {
			printf("猜小了\n");
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL)); //生成随机数
	int input = 0;
	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}