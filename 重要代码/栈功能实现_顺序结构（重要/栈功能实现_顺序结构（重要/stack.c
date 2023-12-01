#define  _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void StackInit(Stack* ps) {
	assert(ps);
	ps->a = NULL;
	ps->top = -1;
	ps->capacity = 0;
}

void StackPush(Stack* ps, SLDataType x) {
	assert(ps);
	if (ps->top + 1 == ps->capacity) {//ÔöÈÝ
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* p = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (p == NULL) {
			perror("realloc p");
			return;
		}
		ps->a = p;
		ps->capacity = newcapacity;
	}
	ps->a[++ps->top] = x;
}

void StackPop(Stack* ps) {
	assert(ps);
	assert(ps->top > -1);
	ps->top--;
}

SLDataType StackTop(Stack* ps) {
	assert(ps);
	assert(ps->top > -1);
	return ps->a[ps->top];
}

int StackSize(Stack* ps) {
	assert(ps);
	return ps->top + 1;
}

bool StackEmpty(Stack* ps) {
	assert(ps);
	return ps->top == -1;
}

void StackDestory(Stack* ps) {
	assert(ps);
	if (ps->a) {
		free(ps->a);
		ps->a = NULL;
		ps->top = 0;
		ps->capacity = 0;
	}
}