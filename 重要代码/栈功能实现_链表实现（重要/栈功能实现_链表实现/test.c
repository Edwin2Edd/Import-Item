#define  _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void StackPush(st** plist, STDatatype x) {
	assert(plist);
	st* p = *plist;
	st* newnode = (st*)malloc(sizeof(st));
	if (newnode == NULL) {
		perror("malloc newnode");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (*plist == NULL) {
		*plist = newnode;
	}
	else {
		*plist = newnode;
		(*plist)->next = p;
	}
}

void StackPop(st** plist) {
	assert(plist);
	assert(*plist);
	st* p = *plist;
	(*plist) = (*plist)->next;
	free(p);
	p = NULL;
}

STDatatype StackTop(st* plist) {
	assert(plist);
	return plist->val;
}

int StackSize(st* plist) {
	assert(plist);
	int size = 0;
	st* cur = plist;
	while (cur) {
		cur = cur->next;
		size++;
	}
	return size;
}

void StackPrint(st* plist) {
	assert(plist);
	st* cur = plist;
	while (cur) {
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

bool StackEmpty(st* plist) {
	return plist == NULL;
}

void StackDestroy(st** plist) {
	assert(plist);
	st* p = *plist;
	while (*plist) {
		*plist = (*plist)->next;
		free(p);
		p = *plist;
	}
}
