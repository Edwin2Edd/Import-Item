#define  _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void test1() {
	SeqList pc;
	SeqListInit(&pc);
	SeqListPushBack(&pc, 1);
	SeqListPushBack(&pc, 2);
	SeqListPushBack(&pc, 3);
	SeqListPushBack(&pc, 4);
	SeqListPrint(&pc);
	SeqListDestroy(&pc);
}

void test2() {
	SeqList pc;
	SeqListInit(&pc);
	SeqListPushBack(&pc, 1);
	SeqListPushBack(&pc, 2);
	SeqListPushBack(&pc, 3);
	SeqListPushBack(&pc, 4);
	SeqListPrint(&pc);
	SeqListPopBack(&pc);
	SeqListPopBack(&pc);
	SeqListPrint(&pc);
	SeqListDestroy(&pc);
}

void test3() {
	SeqList pc;
	SeqListInit(&pc);
	SeqListPushBack(&pc, 1);
	SeqListPushBack(&pc, 2);
	SeqListPushBack(&pc, 3);
	SeqListPushBack(&pc, 4);
	SeqListPrint(&pc);
	SeqListPushFront(&pc, 10);
	SeqListPushFront(&pc, 20);
	SeqListPushFront(&pc, 30);
	SeqListPrint(&pc);
	SeqListPopFront(&pc);
	SeqListPopFront(&pc);
	SeqListPopFront(&pc);
	SeqListPrint(&pc);
	SeqListDestroy(&pc);
}

void test4() {
	SeqList pc;
	SeqListInit(&pc);
	SeqListPushBack(&pc, 1);
	SeqListPushBack(&pc, 2);
	SeqListPushBack(&pc, 3);
	SeqListPushBack(&pc, 4);
	SeqListPrint(&pc);
	SeqListPushFront(&pc, 10);
	SeqListPushFront(&pc, 20);
	SeqListPushFront(&pc, 30);
	SeqListPrint(&pc);
	int n = SeqListFind(&pc, 20);
	printf("%d", n);
	SeqListDestroy(&pc);
}

void test5() {
	SeqList pc;
	SeqListInit(&pc);
	SeqListPushBack(&pc, 1);
	SeqListPushBack(&pc, 2);
	SeqListPushBack(&pc, 3);
	SeqListPushBack(&pc, 4);
	SeqListPrint(&pc);
	SeqListInsert(&pc, 3, 10);
	SeqListInsert(&pc, 3, 20);
	SeqListInsert(&pc, 10, 30);
	SeqListPrint(&pc);
	SeqListErase(&pc, 3);
	SeqListErase(&pc, 3);
	SeqListErase(&pc, 10);
	SeqListPrint(&pc);
	SeqListDestroy(&pc);
}

int main() {
	test5();

}