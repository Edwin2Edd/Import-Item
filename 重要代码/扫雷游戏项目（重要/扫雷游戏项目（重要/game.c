#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化地雷
void InitBoard(char ground[][COLS], int rows, int cols, char set) {
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++) {
			ground[i][j] = set;
		}
	}
}
//打印地雷图
void SurveyBoard(char ground[][COLS], int row, int col) {
	printf("----------扫雷----------\n");
	for (int i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf("%d ", i);
		for (int j = 1; j <= col; j++) {
			printf("%c ", ground[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷----------\n");
}

//随机放置地雷
void SetBoom(char mine[ROWS][COLS], int row, int col) {	
	int count = easy_game;
	while (count){
		int x = rand() % row +1;
		int y = rand() % col +1;
		if (mine[x][y] == '0') {
			mine[x][y] = '1';
			count--;
		}
	}
}

int IsWin(char check[ROWS][COLS], int row, int col) {
	int num = 0;
	//排除一个地雷时便进行累加
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= col; j++){
			if (check[i][j] != '*')
				num++;
		}
	}
	return num;
}

int GetMineCount(char mine[][COLS], int x, int y) {//统计周围雷的数量
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

//递归实现
void GetMineCount_2(char mine[][COLS], char check[][COLS], int x, int y) {
	int count = GetMineCount(mine, x, y);
	if (count == 0) {
		check[x][y] = ' ';
		int i = 0, j = 0;
		for (i = -1; i <= 1; i++) {
			for (j = -1; j <= 1; j++) {
				if ((x + i) > 0 && (y + j) > 0 && (x + i) < ROWS && (y + j) < COLS && check[x + i][y + j] == '*') {
					GetMineCount_2(mine, check, x + i, y + j);
				}
			}
		}
	}
	else {
		check[x][y] = count + '0';
	}
}

//查找地雷
void FindBoom(char mine[][COLS], char check[][COLS], int row, int col) {
	int x;
	int y;
	int win = 0; 
	SurveyBoard(mine, ROW, COL);
	SurveyBoard(check, ROW, COL);
	while (win < row * col - easy_game) {
		
		printf("输入需要查找的坐标->");
		scanf("%d %d", &x, &y);
		if (1 <= x && x <= row && 1 <= y && y <= col)
		{
			if (mine[x][y] == '1') {//检测是否是雷
				//是雷退出游戏
				printf("很抱歉你被炸死了\n");
				SurveyBoard(mine, ROW, COL);
				break;
			}

			if (check[x][y] != '*')
			{
				printf("你已经在这里输入过坐标了,请重新输入!\n");
			}
			else{		 
				//递归实现
				//不是雷，显示区域
				GetMineCount_2(mine, check ,x, y);
				SurveyBoard(check, ROW, COL);
			}
		}
		else{
			printf("非法输入，请重新输入坐标\n");
		}
		win = IsWin(check, row, col);
	}
	if (win == row * col - easy_game)
	{
		printf("恭喜你，排雷成功\n");
		SurveyBoard(mine, ROW, COL);
	}
}