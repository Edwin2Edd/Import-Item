#include "game.h"
//#pragma comment (lib,"三子棋项目.lib")

void menu() {
	printf("**************************\n");
	printf("******    1.play    ******\n");
	printf("******    0.exit    ******\n");
	printf("**************************\n");
}

void game() {
	char set = 0;
	char Char_array[ROW][COL];//创建数组
	InitBoard(Char_array, ROW, COL);//初始化数组内容
	PrintBoard(Char_array, ROW, COL);//打印棋盘
	while (1)
	{
		PlayerMove(Char_array, ROW, COL); 
		PrintBoard(Char_array, ROW, COL);
		//判断棋盘状态
		set = IsWin(Char_array, ROW, COL);
		if (set != 'C') {
			break;
		}
		ComputerMove(Char_array, ROW, COL);
		PrintBoard(Char_array, ROW, COL);
		//判断棋盘状态
		set = IsWin(Char_array, ROW, COL);
		if (set != 'C') {
			break;
		}
	}
	//玩家胜利 -'*' 电脑胜利 -'#' 平局 -'p' 继续 -'C'
	if (set == '*')
		printf("玩家胜利\n");
	else if (set == '#')
		printf("电脑胜利\n");
	else if (set == 'p')
		printf("游戏平局\n");
}

int main() {
	
	srand((unsigned int)time(NULL));
	int select = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}		
	} while (select);
}