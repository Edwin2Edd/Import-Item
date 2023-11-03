#define  _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SListNode* BuySListNode(SLTDataType x) {
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	if (p == NULL) {
		perror("p malloc");
		exit(-1);
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void SListPushBack(SListNode** pplist, SLTDataType x) {
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL) {//
		*pplist = newnode;
	}
	else {
		SListNode* tail = *pplist;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SListNode** pplist) {
	assert(*pplist);
	
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SListNode* tail = *pplist, * prev = NULL;
		while (tail->next) {
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SListPushFront(SListNode** pplist, SLTDataType x) {
	SListNode* tail = BuySListNode(x);
	tail->next = *pplist;
	*pplist = tail;
}

void SListPopFront(SListNode** pplist) {
	assert(*pplist);
	SListNode* tail = *pplist;
	*pplist = (*pplist)->next;
	free(tail);
	tail = NULL;
}

SListNode* SListFind(SListNode* plist, SLTDataType x){
	assert(plist);
	SListNode* tail = plist;
	while (tail != NULL) {
		if (tail->data == x)
			return tail;
		tail = tail->next;
	}
	return NULL;
}


void SListInsertAfter(SListNode* pos, SLTDataType x) {
	assert(pos);
	SListNode* tail = pos;
	SListNode* p = BuySListNode(x);
	p->next = tail->next;
	tail->next = p;
}

void SListEraseAfter(SListNode* pos) {
	assert(pos);
	assert(pos->next);
	SListNode* tail = pos->next;
	pos->next = pos->next->next;
	free(tail);
	tail = NULL;
}

void SLTInsert(SListNode** pplist, SListNode* pos, SLTDataType x) {
	assert(pos);
	SListNode* into = BuySListNode(x);
	SListNode* tail = *pplist;
	if (tail == pos) {
		into->next = *pplist;
		*pplist = into;
		return;
	}
	while (tail->next != pos ) {
		tail = tail->next;
	}
	tail->next = into;
	into->next = pos;
}

void SLTErase(SListNode** pplist, SListNode* pos) {
	assert(pos);
	SListNode* tail = *pplist;
	if (tail == pos) {
		*pplist = tail->next;
		free(tail);
		tail = NULL;
		return;
	}
	while (tail->next != pos) {
		tail = tail->next;
	}
	tail->next = tail->next->next;
	free(pos);
	pos = NULL;
}

void SListPrint(SListNode* plist) {
	SListNode* tail = plist;
	while (tail) {
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}

void SLTDestroy(SListNode** pplist) {
	SListNode* tail = *pplist;
	while (tail){
		SListNode* free_ele = NULL;
		free_ele = tail;
		tail = tail->next;
		free(free_ele);
		free_ele = NULL;
	}
	*pplist = NULL;
}