#define  _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"
void menu() {
	printf("***********************************\n");
	printf("******   1.add      2.del    ******\n");
	printf("******   3.show     4.modify ******\n");
	printf("******   5.query    6.sort   ******\n");
	printf("******   7.reset    0.exit   ******\n");
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
			ReContact(&con);//��ʼ���ṹ������
			break;
		case EXIT:
			DataOutContact(&con);
			DestoryContact(&con);//����ͨѶ¼
			printf("�˳�����");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (select);
}

