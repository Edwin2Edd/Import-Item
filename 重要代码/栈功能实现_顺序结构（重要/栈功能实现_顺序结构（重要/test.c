#define  _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

int main() {
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	while (!StackEmpty(&s)) {
		
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	StackDestory(&s);
}