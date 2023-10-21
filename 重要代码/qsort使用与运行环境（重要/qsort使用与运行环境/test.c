 
//目标：对qsort的使用了解，并且用冒泡排序搭建一个qsort函数使用
//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ConList {
	char name[10];
	int a;
};


void Print_arr(int* arr, size_t arr_size) {//打印整型数组
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(char* e1, char* e2, size_t arr_num) {//进行交换数据
	for (int i = 0; i < arr_num; i++){
		char temp = *e1;
		*e1 = *e2;
		*e2 = temp;
		e1++;
		e2++;
	}
}

int arr_cmp(const void* e1, const void* e2) {//qsort升序排序
	return *(int*)e1 - *(int*)e2;
}

int con_stu_by_cmp(const void* a, const void* b) {//qsort结构体升序排序
	return strcmp(((struct ConList*)a)->name, ((struct ConList*)b)->name);
}

void My_QsortSort(void* arr, size_t a_size, size_t a_num, int(* cmp)(const void* e1, const void* e2)) {
	for (size_t i = 0; i < a_size - 1; i++) {
		for (size_t j = 0; j < a_size - i - 1; j++) {
			if (cmp((char*)arr + j * a_num, (char*)arr + (j + 1) * a_num) > 0) {
				swap((char*)arr + j * a_num, (char*)arr + (j + 1) * a_num, a_num);
			}
		}

	}
}

void test1() {
	int arr[] = { 9,8,7,6,5,4,3,2 };//升序
	size_t arr_size = sizeof(arr) / sizeof(arr[0]);
	Print_arr(arr, arr_size);
	qsort(arr, arr_size, sizeof(arr[0]), arr_cmp);
	Print_arr(arr, arr_size);
}




//void test2() {
//	int arr[] = { 3,2,0,99,6,1,33 };
//	size_t arr_size = sizeof(arr) / sizeof(arr[0]);
//	Print_arr(arr, arr_size);
//	My_QsortSort(arr,arr_size,sizeof(arr[0]),arr_cmp);
//	Print_arr(arr, arr_size);
//
//}

//void test3() {
//	struct ConList con[3] = { {"zhangsan",10},{"wangwu",5},{"lishi",1}};
//	size_t arr_size = sizeof(con) / sizeof(con[0]);
//	My_QsortSort(con, arr_size, sizeof(con[0]), con_stu_by_cmp);
//}

int main() {
	test1();//qsort的使用
	//test2();//搭建qsort整数的排序
	//test3();//搭建qsort结构体的排序
}
