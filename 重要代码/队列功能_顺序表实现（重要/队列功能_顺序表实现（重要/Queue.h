#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DataType;

typedef struct Queue {
	DataType* data;
	int size;
	int capacity;
}Qe;

//��ʼ���ṹ��
void QueueInit(Qe* plist);

//���
void QueuePush(Qe* plist, DataType x);

//����
void QueuePop(Qe* plist);

//��ȡ��ͷԪ��
DataType QueueFront(Qe* plist);

//��ȡ��βԪ��
DataType QueueBack(Qe* plist);

//��ȡ���и���
int QueueSize(Qe* plist);

//������Ϊ�� ��=TRUE
bool QueueEmpty(Qe* q);

//���ٽṹ��
void QueueDestory(Qe* plist);