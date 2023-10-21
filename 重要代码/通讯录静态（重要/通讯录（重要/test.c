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
			InitContact(&con);//初始化结构体内容
			printf("数据重置成功\n");
			break;
		case EXIT:
			printf("退出程序");
			break;
		default:
			printf("输入错误，请重新选择。\n");
			break;
		}
	} while (select);
}

