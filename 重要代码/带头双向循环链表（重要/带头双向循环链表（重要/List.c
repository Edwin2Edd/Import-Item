#define  _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//����˫������ڵ�
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

//��ʼ��ͷ�ڵ�
ListNode* ListInit() {
	ListNode* phead = ListCreate(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//β������ڵ�
void ListPushBack(ListNode* plist, LTDataType x) {
	assert(plist);
	ListNode* tail = plist->prev;
	ListNode* newnode = ListCreate(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = plist;
	plist->prev = newnode;
}

//βɾ����ڵ�
void ListPopBack(ListNode* plist) {
	assert(plist);
	assert(plist->next != plist);
	ListNode* tail = plist->prev;
	plist->prev = tail->prev;
	tail->prev->next = plist;
	free(tail);
}

//ͷ������ڵ�
void ListPushFront(ListNode* plist, LTDataType x) {
	assert(plist);
	ListNode* tail = plist->next;
	ListNode* newnode = ListCreate(x);
	tail->prev = newnode;
	newnode->next = tail;
	plist->next = newnode;
	newnode->prev = plist;
}

//ͷɾ����ڵ�
void ListPopFront(ListNode* plist) {
	assert(plist->next != plist);
	ListNode* tail = plist->next;
	plist->next = tail->next;
	tail->next->prev = plist;
	free(tail);
	tail = NULL;
}

//˫���������
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

//��posǰ��������
void ListInsert(ListNode* plist, ListNode* pos, LTDataType x) {
	assert(plist);
	assert(pos);
	ListNode* newnode = ListCreate(x);
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��posλ�õĽڵ�
void ListErase(ListNode* plist, ListNode* pos) {
	assert(plist);
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

//˫�������ӡ
void ListPrint(ListNode* plist) {
	assert(plist);
	ListNode* tail = plist->next;
	printf("ͷ�ڵ�<->");
	while (tail != plist) {
		printf("%d<->", tail->val);
		tail = tail->next;
	}
	printf("ͷ�ڵ�\n");
}

//˫����������
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