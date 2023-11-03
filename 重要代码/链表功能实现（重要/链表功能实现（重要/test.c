#define  _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void test1() {
	SListNode *phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
}

void test2() {
	SListNode* phead = NULL;
	SListPushFront(&phead, 1);
	//SListPushFront(&phead, 2);
	//SListPushFront(&phead, 3);
	//SListPushFront(&phead, 4);
	SListPopFront(&phead);
	SListPrint(phead);
}

void test3() {
	SListNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListNode * num = SListFind(phead, 4);
	if (num) {
		printf("%d", num->data);
	}
	else {
		printf("数据不存在");
	}
}

void test4() {
	SListNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	SListInsertAfter(SListFind(phead, 3), 5);
	SListPrint(phead);
	SListEraseAfter(SListFind(phead, 4));
	
	SListPrint(phead);
}

void test5() {
	SListNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);
	SLTErase(&phead, SListFind(phead,3));
	SListPrint(phead);
	SLTInsert(&phead, SListFind(phead, 2), 5);
	SLTInsert(&phead, SListFind(phead, 2), 5);
	SListPrint(phead);
	SLTInsert(&phead, SListFind(phead, 1), 3);
	SListPrint(phead);
	SLTInsert(&phead, SListFind(phead, 1), 2);
	SListPrint(phead);
	SLTInsert(&phead, SListFind(phead, 1), 1);
	SListPrint(phead);
	SLTDestroy(&phead);
}

int main() {
	test5();
}