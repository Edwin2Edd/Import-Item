#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu() {
	printf("**************************\n");
	printf("*******   1.play    ******\n");
	printf("*******   0.exit    ******\n");
	printf("**************************\n");
}

void game() {
	char mine[ROWS][COLS] = {0};//存放地雷数组
	char check[ROWS][COLS] = {0};//待查找地雷数组
	//初始化数组内容
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(check, ROWS, COLS, '*');

	//设置炸弹
	SetBoom(mine, ROW, COL);
	//查找炸弹
	FindBoom(mine, check, ROW, COL);

}

int main() {
	int select = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的选择->");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误重新选择\n");
			break;
		}
	} while (select);
}