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

//初始化结构体
void QueueInit(Qe* plist);

//入队
void QueuePush(Qe* plist, DataType x);

//出队
void QueuePop(Qe* plist);

//获取队头元素
DataType QueueFront(Qe* plist);

//获取队尾元素
DataType QueueBack(Qe* plist);

//获取队列个数
int QueueSize(Qe* plist);

//检测队列为空 空=TRUE
bool QueueEmpty(Qe* q);

//销毁结构体
void QueueDestory(Qe* plist);