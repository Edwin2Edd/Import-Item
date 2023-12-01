#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
typedef int HPDatatpye;

void Swap(HPDatatpye* p, HPDatatpye* q) {
	HPDatatpye emp = *p;
	*p = *q;
	*q = emp;
}

void AjionUp(HPDatatpye* arr, int child) {
	int parent = (child - 1) / 2;
	while (child) {
		if (arr[parent] < arr[child]) {
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void AjoinDown(HPDatatpye* arr, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && arr[child] < arr[child + 1]) {
			child = child + 1;
		}
		if (arr[parent] < arr[child]) {
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(HPDatatpye *arr ,int n) {
	//大堆向上调整
	/*for (int i = 1; i < n; i++)
		AjionUp(arr, i);*/

	//大堆向下取整
	int parent = (n - 1 - 1) / 2;
	while (parent >= 0) {
		AjoinDown(arr, n, parent);
		parent--;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	int arr_size = n - 1;
	while (arr_size) {
		Swap(&arr[0], &arr[arr_size]);
		AjoinDown(arr, arr_size, 0);
		arr_size--;
	}
}


int main() {
	HPDatatpye arr[] = { 4,1,2,5,6,10,9,7,0 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}