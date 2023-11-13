#define  _CRT_SECURE_NO_WARNINGS 1
#include "List.h"


void test1() {
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
}

void test2() {
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
}

void test3() {
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListNode* n = ListFind(plist, 1);
	/*printf("%d", n->val);*/
	ListInsert(plist, n, 1);
	ListPrint(plist);
	ListErase(plist, n);
	ListPrint(plist);
	ListDestory(plist);
}

int main() {
	test2();
}