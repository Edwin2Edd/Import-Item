#define  _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

int main() {
	Queue s;
	QListInit(&s);
	QListPush(&s, 1);
	QListPush(&s, 2);
	QListPush(&s, 3);
	QListPush(&s, 4);
	QListPush(&s, 6);
	printf("ͷ��Ԫ��Ϊ%d\n", QueueFront(&s));
	printf("β��Ԫ��Ϊ%d\n", QueueBack(&s));
	printf("Ԫ�س���Ϊ%d\n", QueueSize(&s));
	while (!QueueEmpty(&s)) {
		printf("%d ", QueueFront(&s));
		QListPop(&s);
	}
	QListDestory(&s);
}