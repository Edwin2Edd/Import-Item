#include <stdio.h>
int main() {
	int num[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left, middle, right, target;
	printf("����Ҫ���ҵ�����");
	scanf("%d", &target);
	left = 0;
	right = 10 - 1;
	
	while (left < right) {
		middle = left + (right - left) / 2;
		if (num[middle] > target) {
			right = middle;
		}
		else if (num[middle] < target) {
			left = middle;
		}
		else {
			printf("����ҵ�%d�±���%d", target, middle);
			break;
		}
	}
	if (left == right) {
		printf("����ʧ��");
	}
}