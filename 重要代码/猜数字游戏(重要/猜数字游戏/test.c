#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>


void menu() {
	printf("*******************************\n");
	printf("******     1.��ʼ��Ϸ     *****\n");
	printf("******     0.������Ϸ     *****\n");
	printf("*******************************\n");
}



int Input_Num() {//�������ж�����Ϸ���
	int data = 0;
	int num = 0;
	do
	{
		data = (scanf("%d", &num));
		if (data != 1) {
			printf("��������������룺");
			while (getchar() != '\n');
		}
	} while (data != 1);
	return num;
}

void Game_Module() {//�ж�ģ��
	int re = rand() % 100 + 1;
	printf("��һ�����Ƕ��٣�");
	int per_num = Input_Num();
	while (1) {
		if (per_num > re) {
			printf("���´���,���²£�");
			per_num = Input_Num(); 
		}
		else if (per_num < re)
		{
			printf("����С�ˣ����²£�");
			per_num = Input_Num();
		}
		else
		{
			printf("�¶���\n");
			break;
		}
	}

}

int main() {
	srand((unsigned int)time(NULL));
	int chuise = 0;
	do
	{
		
		menu();//��ӡ�˵���
		printf("������->");
		chuise = Input_Num();//��������
		switch (chuise)
		{
		case 1:
			Game_Module();
			break;
		case 0:
			printf("�˳���Ϸ");
			Sleep(1000);
			break;
		default:
			printf("�����������ѡ��\n");
			break;
		}
	} while (chuise);
}