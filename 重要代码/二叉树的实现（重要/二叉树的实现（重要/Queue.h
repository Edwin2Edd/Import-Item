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

//初始化队列
void QListInit(Queue* q);
//队列入队列
void QListPush(Queue* q, DataType x);
//队列出队列
void QListPop(Queue* q);
//获取队列头部元素
DataType QueueFront(Queue* q);
//获取队列尾部元素
DataType QueueBack(Queue* q);
//获取队列的元素个数
int QueueSize(Queue* q);
//检测队列为空 空=TRUE
bool QueueEmpty(Queue* q);
//销毁队列
void QListDestory(Queue* q);

