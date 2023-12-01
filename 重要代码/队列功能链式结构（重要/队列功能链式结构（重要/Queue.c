#define  _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//��ʼ������
void QListInit(Queue* q) {
	assert(q);
	q->phead = q->plist = NULL;
	q->size = 0;
}
//���������
void QListPush(Queue* q, DataType x) {
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL) {
		perror("malloc newnode");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (q->phead == NULL) {
		q->phead = q->plist = newnode;
	}
	else {
		q->plist->next = newnode;
		q->plist = newnode;
	}
	q->size++;
}
//���г�����
void QListPop(Queue* q) {
	assert(q);
	assert(q->phead);
	QNode* del = q->phead;
	if (del->next == NULL) {
		free(del);
		q->phead = q->plist = NULL;
	}
	else {
		QNode* next = del->next;
		free(del);
		del = NULL;
		q->phead = next;
	}
	q->size--;
}
//��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q) {
	assert(q);
	assert(q->phead);
	return q->phead->val;
}
//��ȡ����β��Ԫ��
DataType QueueBack(Queue* q) {
	assert(q);
	assert(q->plist);
	return q->plist->val;
}
//��ȡ���е�Ԫ�ظ���
int QueueSize(Queue* q) {
	assert(q);
	assert(q->phead);
	return q->size;
}
//������Ϊ�� ��=TRUE
bool QueueEmpty(Queue* q) {
	assert(q);
	return q->phead == NULL;
}
//���ٶ���
void QListDestory(Queue* q) {
	assert(q);
	QNode* tail = q->phead;
	while (tail) {
		QNode* next = tail->next;
		free(tail);
		tail = next;
	}
	q->phead = q->plist = NULL;
	q->size = 0;
}