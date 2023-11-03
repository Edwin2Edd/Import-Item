#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType; 

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListPushBack(SListNode** pplist, SLTDataType x);//β��
void SListPopBack(SListNode** pplist);//βɾ
void SListPushFront(SListNode** pplist, SLTDataType x);//ͷ��
void SListPopFront(SListNode** pplist);//ͷɾ
SListNode* SListFind(SListNode* plist, SLTDataType x);//��������
void SListInsertAfter(SListNode* pos, SLTDataType x);//pos֮��λ�ò�������
void SListEraseAfter(SListNode* pos);//pos֮���λ��ɾ��
void SLTInsert(SListNode** pplist, SListNode* pos, SLTDataType x);//posλ��ǰ���������
void SLTErase(SListNode** pplist, SListNode* pos);//ɾ��posλ��
void SListPrint(SListNode* plist);//��ӡ
void SLTDestroy(SListNode** pphead);//����