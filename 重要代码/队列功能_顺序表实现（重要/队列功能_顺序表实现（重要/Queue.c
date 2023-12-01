#define  _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//��ʼ���ṹ��
void QueueInit(Qe* plist) {
	plist->data = NULL;
	plist->capacity = 0;
	plist->size = 0;
}

//���
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

//����
void QueuePop(Qe* plist) {
	assert(plist);
	for (int i = 1; i < plist->size; i++)
		plist->data[i - 1] = plist->data[i];
	plist->size--;
}

//��ȡ��ͷԪ��
DataType QueueFront(Qe* plist) {
	assert(plist);
	return plist->data[0];
}

//��ȡ��βԪ��
DataType QueueBack(Qe* plist) {
	assert(plist);
	return plist->data[plist->size - 1];
}

//��ȡ���и���
int QueueSize(Qe* plist) {
	assert(plist);
	return plist->size;
}

//������Ϊ�� ��=TRUE
bool QueueEmpty(Qe* plist) {
	assert(plist);
	return plist->size == 0;
}

//���ٽṹ��
void QueueDestory(Qe* plist) {
	if (plist->data) {
		free(plist->data);
		plist->data = NULL;
		plist->capacity = 0;
		plist->size = 0;
	}
}