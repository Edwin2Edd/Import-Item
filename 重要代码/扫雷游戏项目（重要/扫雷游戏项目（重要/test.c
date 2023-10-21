#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu() {
	printf("**************************\n");
	printf("*******   1.play    ******\n");
	printf("*******   0.exit    ******\n");
	printf("**************************\n");
}

void game() {
	char mine[ROWS][COLS] = {0};//��ŵ�������
	char check[ROWS][COLS] = {0};//�����ҵ�������
	//��ʼ����������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(check, ROWS, COLS, '*');

	//����ը��
	SetBoom(mine, ROW, COL);
	//����ը��
	FindBoom(mine, check, ROW, COL);

}

int main() {
	int select = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("���������ѡ��->");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (select);
}