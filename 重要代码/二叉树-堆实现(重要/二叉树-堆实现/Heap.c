#define  _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//�ѳ�ʼ��
void HeapInit(hp* php){
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}
//������
void HeapDestory(hp* php) {
	assert(php);
	if (php->a) {
		free(php->a);
		php->size = 0;
		php->capacity = 0;
	}
}

void Swap(HPDataType* p, HPDataType* q) {
	HPDataType emp = *p;
	*p = *q;
	*q = emp;
}

//����ȡ��
void AjoinUp(HPDataType* a, int child) {
	int parent = (child - 1) / 2;
	while (child>0) {
		if (a[parent] > a[child]) {
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

//�Ѳ���
void HeapPush(hp* php, HPDataType x) {
	assert(php);
	if (php->size == php->capacity) {
		int newcapa = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* p = (HPDataType*)realloc(php->a, newcapa * sizeof(HPDataType));
		if (p == NULL) {
			perror("realloc p");
			exit(-1);
		}
		php->a = p;
		php->capacity = newcapa;
	}
	php->a[php->size] = x;
	php->size++;
	AjoinUp(php->a, php->size - 1);
}

//����ȡ��
void AjoinDown(HPDataType* a,int size ,int parent){
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && a[child] > a[child + 1]) {
			child = child + 1;
		}
		if (a[parent] > a[child]) {
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

//��ɾ��
void HeapPop(hp* php) { 
	assert(php);
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	AjoinDown(php->a,php->size -1 , 0);
	php->size--;
}

// ȡ�Ѷ�������
HPDataType HeapTop(hp* php) {
	return php->a[0];
}
// �ѵ����ݸ���
int HeapSize(hp* php) {
	return php->size;
}
// �ѵ��п�
bool HeapEmpty(hp* php) {
	return php->size == 0;
}