#define  _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SeqList* pc) {
	pc->data = NULL;
	pc->size = 0;
	pc->capacity = 0;
}

void SeqListDestroy(SeqList* pc) {
	assert(pc);
	if (pc->data != NULL) {
		free(pc->data);
		pc->data = NULL;
		pc->size = 0;
		pc->capacity = 0;
	}
}

void SLCheckCapacity(SeqList* pc) {
	assert(pc);
	if (pc->capacity == pc->size) {
		int newCapacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
		SLDataType* emp = (SLDataType*)realloc(pc->data, sizeof(SeqList) * newCapacity);
		if (emp == NULL) {
			perror("realloc emp");
			exit(-1);
		}
		pc->data = emp;
		pc->capacity = newCapacity;
	}
}

void SeqListPushBack(SeqList* pc, int x) {
	assert(pc);
	SLCheckCapacity(pc);
	pc->data[pc->size] = x;
	pc->size++;
}

void SeqListPopBack(SeqList* pc) {
	assert(pc);
	//assert(pc->size != 0);//暴力
	if (pc->size == 0) {
		printf("没数据删除失败\n");
		return;
	}
	pc->size--;
}

void SeqListPushFront(SeqList* pc, int x) {
	assert(pc);
	SLCheckCapacity(pc);
	for (int i = pc->size; i > 0; i--) {
		pc->data[i] = pc->data[i - 1];
	}
	pc->data[0] = x;
	pc->size++;
}

void SeqListPopFront(SeqList* pc) {
	assert(pc);
	//assert(pc->size != 0);//暴力
	if (pc->size == 0) {
		printf("没数据删除失败\n");
		return;
	}
	for (int i = 1; i < pc->size; i++) {
		pc->data[i - 1] = pc->data[i];
	}
	pc->size--;
}

int SeqListFind(SeqList* pc, int x) {
	assert(pc);
	//assert(pc->size > 0);//暴力
	if (pc->size == 0) {
		printf("无数据查找失败\n");
		return;
	}
	for (int i = 0; i < pc->size; i++) {
		if (pc->data[i] == x)
			return i + 1;
	}
	printf("数据不存在\n");
	return -1;
}

void SeqListInsert(SeqList* pc, int pos, SLDataType x) {
	assert(pc);
	SLCheckCapacity(pc);
	if ((0 > pos || pos > pc->size)) {
		printf("位置错误，添加失败\n");
		return;
	}
	int s = pos - 1;
	for (int i = pc->size; i > s; i--) {
		pc->data[i] = pc->data[i - 1];
	}
	pc->data[s] = x;
	pc->size++;
}

void SeqListErase(SeqList* pc, int pos) {
	assert(pc);
	//assert(pc->size != 0);//暴力
	if (pc->size == 0 || (0 > pos || pos > pc->size)) {
		printf("删除失败\n");
		return;
	}
	int s = pos - 1;
	for (int i = s + 1; i < pc->size; i++) {
		pc->data[i - 1] = pc->data[i];
	}
	pc->size--;
}

void SeqListPrint(SeqList* pc) {
	assert(pc);
	//assert(pc->size > 0);//暴力
	if (pc->size == 0 ) {
		printf("无数据打印失败\n");
		return;
	}
	for (int i = 0; i < pc->size; i++) {
		printf("%d ", pc->data[i]);
	}
	printf("\n");
}