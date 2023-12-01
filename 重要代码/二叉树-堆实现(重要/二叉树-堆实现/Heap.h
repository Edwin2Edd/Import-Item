#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


typedef int HPDataType;
typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}hp;

//�ѳ�ʼ��
void HeapInit(hp* php);
//������
void HeapDestory(hp* php);
//�Ѳ���
void HeapPush(hp* php, HPDataType x);
//��ɾ��
void HeapPop(hp* php);
// ȡ�Ѷ�������
HPDataType HeapTop(hp* php);
// �ѵ����ݸ���
int HeapSize(hp* php);
// �ѵ��п�
bool HeapEmpty(hp* php);