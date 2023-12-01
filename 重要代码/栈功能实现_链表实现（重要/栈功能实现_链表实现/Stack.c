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
	printf("栈顶元素是：%d\n", StackTop(phead));
	StackPop(&phead);
	StackPop(&phead);
	StackPrint(phead);
	printf("栈顶元素是：%d\n", StackTop(phead));
	printf("栈里有效数据是：%d\n", StackSize(phead));
	StackDestroy(&phead);
}