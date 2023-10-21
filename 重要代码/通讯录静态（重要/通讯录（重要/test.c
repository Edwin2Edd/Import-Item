#define  _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"
void menu() {
	printf("***********************************\n");
	printf("******   1.ADD      2.DEL    ******\n");
	printf("******   3.SHOW     4.MODIFY ******\n");
	printf("******   5.QUERY    6.SORT   ******\n");
	printf("******   7.RESET    0.EXIT   ******\n");
	printf("***********************************\n");
}

enum choose
{
	EXIT,
	ADD,
	DEL,
	SHOW,
	MODIFY,
	QUERY,
	SORT,
	RESET
};

int main() {
	int select = 0;
	Contact con;
	InitContact(&con);//��ʼ���ṹ������
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &select);
		switch (select)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case MODIFY:
			MoContact(&con);
			break;
		case QUERY:
			QuContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case RESET:
			InitContact(&con);//��ʼ���ṹ������
			printf("�������óɹ�\n");
			break;
		case EXIT:
			printf("�˳�����");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (select);
}

