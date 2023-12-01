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
	printf("头部元素为%d\n", QueueFront(&s));
	printf("尾部元素为%d\n", QueueBack(&s));
	printf("元素长度为%d\n", QueueSize(&s));
	while (!QueueEmpty(&s)) {
		printf("%d ", QueueFront(&s));
		QListPop(&s);
	}
	QListDestory(&s);
}