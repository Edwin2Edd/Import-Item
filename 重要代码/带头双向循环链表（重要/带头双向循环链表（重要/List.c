#define  _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//创建双向链表节点
ListNode* ListCreate(LTDataType x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		perror("plink malloc");
		exit(-1);
	}
	newnode->val = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

//初始化头节点
ListNode* ListInit() {
	ListNode* phead = ListCreate(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//尾插链表节点
void ListPushBack(ListNode* plist, LTDataType x) {
	assert(plist);
	ListNode* tail = plist->prev;
	ListNode* newnode = ListCreate(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = plist;
	plist->prev = newnode;
}

//尾删链表节点
void ListPopBack(ListNode* plist) {
	assert(plist);
	assert(plist->next != plist);
	ListNode* tail = plist->prev;
	plist->prev = tail->prev;
	tail->prev->next = plist;
	free(tail);
}

//头插链表节点
void ListPushFront(ListNode* plist, LTDataType x) {
	assert(plist);
	ListNode* tail = plist->next;
	ListNode* newnode = ListCreate(x);
	tail->prev = newnode;
	newnode->next = tail;
	plist->next = newnode;
	newnode->prev = plist;
}

//头删链表节点
void ListPopFront(ListNode* plist) {
	assert(plist->next != plist);
	ListNode* tail = plist->next;
	plist->next = tail->next;
	tail->next->prev = plist;
	free(tail);
	tail = NULL;
}

//双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x) {
	assert(plist);
	//assert(plist->next != plist);
	ListNode* cur = plist->next;
	while (cur != plist) {
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//在pos前插入数据
void ListInsert(ListNode* plist, ListNode* pos, LTDataType x) {
	assert(plist);
	assert(pos);
	ListNode* newnode = ListCreate(x);
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
}

//删除pos位置的节点
void ListErase(ListNode* plist, ListNode* pos) {
	assert(plist);
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

//双向链表打印
void ListPrint(ListNode* plist) {
	assert(plist);
	ListNode* tail = plist->next;
	printf("头节点<->");
	while (tail != plist) {
		printf("%d<->", tail->val);
		tail = tail->next;
	}
	printf("头节点\n");
}

//双向链表销毁
void ListDestory(ListNode* plist) {
	assert(plist);
	ListNode* tail = plist->next;
	while (tail != plist) {
		ListNode* fnode = tail;
		tail = tail->next;
		free(fnode);
	}
	free(tail);
	
}