#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SeqList {
	SLDataType* data;
	int size;
	int capacity;
}SeqList;

void SeqListInit(SeqList *pc);//初始化线性表
void SeqListDestroy(SeqList* pc);//销毁线性表
void SeqListPushBack(SeqList* pc, int x);//尾插
void SeqListPopBack(SeqList* pc);//尾删
void SeqListPushFront(SeqList* pc, int x);//头插
void SeqListPopFront(SeqList* pc);//头删
int SeqListFind(SeqList* pc, int x);//查找
void SeqListInsert(SeqList* pc, int pos, SLDataType x);//指定位置插入
void SeqListErase(SeqList* pc, int pos);//指定位置删除
void SeqListPrint(SeqList* pc);//打印