#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char DataType;
typedef struct QListNode {
	DataType val;
	struct QListNode* next;
}QNode;

typedef struct Queue {
	QNode* phead;
	QNode* plist;
	int size;
}Queue;

//��ʼ������
void QListInit(Queue* q);
//���������
void QListPush(Queue* q, DataType x);
//���г�����
void QListPop(Queue* q);
//��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q);
//��ȡ����β��Ԫ��
DataType QueueBack(Queue* q);
//��ȡ���е�Ԫ�ظ���
int QueueSize(Queue* q);
//������Ϊ�� ��=TRUE
bool QueueEmpty(Queue* q);
//���ٶ���
void QListDestory(Queue* q);

