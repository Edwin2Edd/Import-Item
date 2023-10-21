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
	InitContact(&con);//初始化结构体内容
	do
	{
		menu();
		printf("请选择->");
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
			ReContact(&con);//初始化结构体内容
			break;
		case EXIT:
			DataOutContact(&con);
			DestoryContact(&con);//销毁通讯录
			printf("退出程序");
			break;
		default:
			printf("输入错误，请重新选择。\n");
			break;
		}
	} while (select);
}

