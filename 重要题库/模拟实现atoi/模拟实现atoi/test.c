#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<limits.h>
enum state{
	Value,
	ErrValue
}statue = ErrValue;

int my_atoi(const char* arr) {
	assert(arr);
	char* p = (char*)arr;
	long long n = 0;
	if (*arr == '\0')
		return 0;
	while (*p == ' ')
		*p++;
	int flag = 1;
	if (*p == '+') {
		p++;
		flag = 1;
	}		
	else if (*p == '-') {
		p++;
		flag = -1;
	}
	while (*p){
		if (isdigit(*p)) {
			n = n * 10 + flag * (*p - '0');
			if (n > INT_MAX) {
				n = INT_MAX;
				break;
			}
			else if (n < INT_MIN) {
				n = INT_MIN;
				break;
			}
		}
		else
			break;
		p++;
	}
	if (*p == '\0')
		statue = Value;
	return (int)n;
}

int main() {
	char arr[] = "    -12345abc";
	int num = my_atoi(arr);
	if (statue == 0)
		printf("正常转换");
	else
		printf("异常转换");
	printf(" %d", num);
}