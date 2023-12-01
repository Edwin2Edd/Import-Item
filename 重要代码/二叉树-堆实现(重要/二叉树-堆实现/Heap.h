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

//堆初始化
void HeapInit(hp* php);
//堆销毁
void HeapDestory(hp* php);
//堆插入
void HeapPush(hp* php, HPDataType x);
//堆删除
void HeapPop(hp* php);
// 取堆顶的数据
HPDataType HeapTop(hp* php);
// 堆的数据个数
int HeapSize(hp* php);
// 堆的判空
bool HeapEmpty(hp* php);