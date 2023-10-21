#include "game.h"
//#pragma comment (lib,"��������Ŀ.lib")

void menu() {
	printf("**************************\n");
	printf("******    1.play    ******\n");
	printf("******    0.exit    ******\n");
	printf("**************************\n");
}

void game() {
	char set = 0;
	char Char_array[ROW][COL];//��������
	InitBoard(Char_array, ROW, COL);//��ʼ����������
	PrintBoard(Char_array, ROW, COL);//��ӡ����
	while (1)
	{
		PlayerMove(Char_array, ROW, COL); 
		PrintBoard(Char_array, ROW, COL);
		//�ж�����״̬
		set = IsWin(Char_array, ROW, COL);
		if (set != 'C') {
			break;
		}
		ComputerMove(Char_array, ROW, COL);
		PrintBoard(Char_array, ROW, COL);
		//�ж�����״̬
		set = IsWin(Char_array, ROW, COL);
		if (set != 'C') {
			break;
		}
	}
	//���ʤ�� -'*' ����ʤ�� -'#' ƽ�� -'p' ���� -'C'
	if (set == '*')
		printf("���ʤ��\n");
	else if (set == '#')
		printf("����ʤ��\n");
	else if (set == 'p')
		printf("��Ϸƽ��\n");
}

int main() {
	
	srand((unsigned int)time(NULL));
	int select = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("�����������������\n");
			break;
		}		
	} while (select);
}