#include<stdio.h>

int input_num() {
	int num = 0;
	int data = 0;
	do
	{
		data = (scanf("%d", &num));
		if (data != 1) {
			printf("��������������룺");
			while (getchar() != '\n');
		}
	} while (data != 1);
	return num;
}

int main()
{
	int a;
	a = input_num();
	printf("%d", a);

}
