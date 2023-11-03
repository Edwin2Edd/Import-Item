#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType; 

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** pplist, SLTDataType x);//尾插
void SListPopBack(SListNode** pplist);//尾删
void SListPushFront(SListNode** pplist, SLTDataType x);//头插
void SListPopFront(SListNode** pplist);//头删
SListNode* SListFind(SListNode* plist, SLTDataType x);//查找数据
void SListInsertAfter(SListNode* pos, SLTDataType x);//pos之后位置插入数据
void SListEraseAfter(SListNode* pos);//pos之后的位置删除
void SLTInsert(SListNode** pplist, SListNode* pos, SLTDataType x);//pos位置前面插入数据
void SLTErase(SListNode** pplist, SListNode* pos);//删除pos位置
void SListPrint(SListNode* plist);//打印
void SLTDestroy(SListNode** pphead);//销毁