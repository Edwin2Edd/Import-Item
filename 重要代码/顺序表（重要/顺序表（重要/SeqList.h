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

void SeqListInit(SeqList *pc);//��ʼ�����Ա�
void SeqListDestroy(SeqList* pc);//�������Ա�
void SeqListPushBack(SeqList* pc, int x);//β��
void SeqListPopBack(SeqList* pc);//βɾ
void SeqListPushFront(SeqList* pc, int x);//ͷ��
void SeqListPopFront(SeqList* pc);//ͷɾ
int SeqListFind(SeqList* pc, int x);//����
void SeqListInsert(SeqList* pc, int pos, SLDataType x);//ָ��λ�ò���
void SeqListErase(SeqList* pc, int pos);//ָ��λ��ɾ��
void SeqListPrint(SeqList* pc);//��ӡ