#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>


void menu() {
	printf("*******************************\n");
	printf("******     1.开始游戏     *****\n");
	printf("******     0.结束游戏     *****\n");
	printf("*******************************\n");
}



int Input_Num() {//输入且判断输入合法性
	int data = 0;
	int num = 0;
	do
	{
		data = (scanf("%d", &num));
		if (data != 1) {
			printf("输入错误，重新输入：");
			while (getchar() != '\n');
		}
	} while (data != 1);
	return num;
}

void Game_Module() {//判断模块
	int re = rand() % 100 + 1;
	printf("猜一下数是多少：");
	int per_num = Input_Num();
	while (1) {
		if (per_num > re) {
			printf("数猜大了,重新猜：");
			per_num = Input_Num(); 
		}
		else if (per_num < re)
		{
			printf("数猜小了，重新猜：");
			per_num = Input_Num();
		}
		else
		{
			printf("猜对啦\n");
			break;
		}
	}

}

int main() {
	srand((unsigned int)time(NULL));
	int chuise = 0;
	do
	{
		
		menu();//打印菜单栏
		printf("请输入->");
		chuise = Input_Num();//输入数字
		switch (chuise)
		{
		case 1:
			Game_Module();
			break;
		case 0:
			printf("退出游戏");
			Sleep(1000);
			break;
		default:
			printf("输入错误，重新选择\n");
			break;
		}
	} while (chuise);
}