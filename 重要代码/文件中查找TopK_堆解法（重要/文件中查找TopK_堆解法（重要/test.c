#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef int HPDatatpye;

void Swap(HPDatatpye* p, HPDatatpye* q) {
	HPDatatpye emp = *p;
	*p = *q;
	*q = emp;
}

void AjionUp(HPDatatpye* arr, int child) {
	int parent = (child - 1) / 2;
	while (child) {
		if (arr[parent] > arr[child]) {
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
		if (child + 1 < size && arr[child] > arr[child + 1]) {
			child = child + 1;
		}
		if (arr[parent] > arr[child]) {
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void CreateNum(const char * file) {
	int line = 100000;
	srand((unsigned int)time(NULL));
	FILE* fp_in = fopen(file, "w");
	if (fp_in == NULL) {
		perror("fopen error");
		exit(-1);
	}
	for (int i = 0; i < line; i++) {
		int x = rand() % 100000;
		fprintf(fp_in, "%d\n", x);
	}
	fclose(fp_in);
}

void FindTop(const char* file, int n) {
	HPDatatpye* arr_num = (HPDatatpye*)malloc(sizeof(HPDatatpye) * n);
	if (arr_num == NULL) {
		perror("malloc error");
		exit(-1);
	}
	FILE* fp_out = fopen(file, "r");
	if (fp_out == NULL) {
		perror("fopen error");
		exit(-1);
	}
	for (int i = 0; i < n; i++) {
		fscanf(fp_out, "%d", &arr_num[i]);
		AjionUp(arr_num, i);
	}
	int x = 0;
	
	while ((fscanf(fp_out, "%d", &x)) != EOF) {
		if (x > arr_num[0]) {
			arr_num[0] = x;
			AjoinDown(arr_num, n, 0);
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr_num[i]);
	}
	printf("\n");

	free(arr_num);
	fclose(fp_out);
}

int main() {
	//CreateNum("num.txt");
	FindTop("num.txt", 5);
}
