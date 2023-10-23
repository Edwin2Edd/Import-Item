#define  _CRT_SECURE_NO_WARNINGS 1

//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

#include<stdio.h>
#include<string.h>

void pd_move(char arr[], int f) {
	size_t len = strlen(arr);
	f %= len;
	for (size_t i = 0; i < f; i++){
		char tmp = *arr;
		for (size_t j = 0; j < len; j++){
			*(arr + j) = *(arr + j + 1);
		}
		*(arr + len - 1) = tmp;
	}
}

void reverse(char* left, char* right) {
	while (left<right){
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr, int f) {
	size_t len = strlen(arr);
	f %= len;
	reverse(arr, arr + f - 1);
	reverse(arr + f, arr + len - 1);
	reverse(arr, arr + len - 1);
}

int main() {
	char arr[] = "ABCDEF";
	//pd_move(arr, 14);//�������
	left_move(arr, 14);//������ת��
	printf("%s", arr);
}