#define  _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

int main() {
	st* phead = NULL;
	StackPush(&phead, 1);
	StackPush(&phead, 2);
	StackPush(&phead, 3);
	StackPush(&phead, 4);
	StackPush(&phead, 5);
	StackPrint(phead);
	printf("ջ��Ԫ���ǣ�%d\n", StackTop(phead));
	StackPop(&phead);
	StackPop(&phead);
	StackPrint(phead);
	printf("ջ��Ԫ���ǣ�%d\n", StackTop(phead));
	printf("ջ����Ч�����ǣ�%d\n", StackSize(phead));
	StackDestroy(&phead);
}