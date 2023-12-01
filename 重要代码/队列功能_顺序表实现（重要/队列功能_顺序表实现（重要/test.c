#define  _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

int main() {
	Qe phead;
	QueueInit(&phead);
	QueuePush(&phead, 1);
	QueuePush(&phead, 2);
	QueuePush(&phead, 3);
	QueuePush(&phead, 4);
	QueuePush(&phead, 5);
	while (!QueueEmpty(&phead)) {
		printf("%d ", QueueFront(&phead));
		QueuePop(&phead);
	}
	QueueDestory(&phead);
}