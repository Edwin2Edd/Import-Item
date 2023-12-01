#define  _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//初始化结构体
void QueueInit(Qe* plist) {
	plist->data = NULL;
	plist->capacity = 0;
	plist->size = 0;
}

//入队
void QueuePush(Qe* plist, DataType x) {
	assert(plist);
	if (plist->capacity == plist->size) {
		int newcapa = plist->capacity == 0 ? 4 : plist->capacity * 2;
		DataType* p = (DataType*)realloc(plist->data, sizeof(DataType) * newcapa);
		assert(p);
		plist->data = p;
		plist->capacity = newcapa;
	}
	plist->data[plist->size] = x;
	plist->size++;
}

//出队
void QueuePop(Qe* plist) {
	assert(plist);
	for (int i = 1; i < plist->size; i++)
		plist->data[i - 1] = plist->data[i];
	plist->size--;
}

//获取队头元素
DataType QueueFront(Qe* plist) {
	assert(plist);
	return plist->data[0];
}

//获取队尾元素
DataType QueueBack(Qe* plist) {
	assert(plist);
	return plist->data[plist->size - 1];
}

//获取队列个数
int QueueSize(Qe* plist) {
	assert(plist);
	return plist->size;
}

//检测队列为空 空=TRUE
bool QueueEmpty(Qe* plist) {
	assert(plist);
	return plist->size == 0;
}

//销毁结构体
void QueueDestory(Qe* plist) {
	if (plist->data) {
		free(plist->data);
		plist->data = NULL;
		plist->capacity = 0;
		plist->size = 0;
	}
}