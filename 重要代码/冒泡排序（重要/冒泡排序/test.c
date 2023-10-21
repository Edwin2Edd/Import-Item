#include<stdio.h>

void sort(int* arr, int num) {
	int temp;
	for (int i = 0; i < num - 1; i++){
		for (int j = 0; j < num - i - 1; j++) {			
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void Print_arr(int* arr, int num) {
	for (int i = 0; i < num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int array_num[] = { 4,1,3,5,7,9,2,4,0,10,23 };
	int num = sizeof(array_num) / sizeof(array_num[0]);
	Print_arr(array_num, num);
	sort(array_num, num);//ÉıĞòÅÅĞò
	Print_arr(array_num, num);

}