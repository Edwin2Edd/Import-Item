#define  _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

int main() {
	int a[] = { 2,46,7,4,3,7,9,0,40 };
	hp phead;
	HeapInit(&phead);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		HeapPush(&phead, a[i]);
	}
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%d ", phead.a[i]);
	}
	printf("\n");
	//int k = 3;
	//while (k--) {
	//	HeapPop(&phead);
	//}
	
	while (!HeapEmpty(&phead)) {
		printf("%d ", HeapTop(&phead));
		HeapPop(&phead);
	}

	HeapDestory(&phead);
}