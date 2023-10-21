#include "game.h"

void InitBoard(char arr[][COL], int row, int col) {//初始化数组
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++) {
			arr[i][j] = ' ';
		}
	}
}

void PrintBoard(char arr[][COL], int row, int col) {//打印数组内容
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < col - 1) {
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char arr[][COL], int row, int col) {//玩家移动
	printf("玩家下棋 ->");
	int x, y;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= row) {
			if (arr[x - 1][y - 1] == ' ') {
				arr[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("位置已被占用，请重新输入 ->");
			}			
		}
		else
			printf("输入错误，重新输入");
	}	
}

void ComputerMove(char arr[][COL], int row, int col) {//电脑移动
	printf("电脑下棋\n");
	int x = rand() % row;
	int y = rand() % col;
	while (1)
	{
		if (arr[x][y] == ' ') {
			arr[x][y] = '#';
			break;
		}
		x = rand() % row;
		y = rand() % col;
	}
}

//判断棋盘状况
//判断棋盘是否满
static int IsFull(char arr[][COL], int row, int col) {
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//玩家胜利 -'*' 电脑胜利 -'#' 平局 -'p' 继续 -'C'
char IsWin(char arr[][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}
	for (int i = 0; i < col; i++) {
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
		return arr[1][1];
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[1][1] != ' ')
		return arr[1][1];
	if (IsFull(arr, row, col)) {//判断棋盘是否满
		return 'p';
	}
	else{
		return 'C';
	}
}