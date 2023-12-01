#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int SLDataType;

typedef struct Stack {
	SLDataType* a;
	int top;//栈顶
	int capacity;//容量
}Stack;

//初始化栈
void StackInit(Stack* ps);  
//入栈
void StackPush(Stack* ps, SLDataType x);
//出栈
void StackPop(Stack* ps);
//获取栈顶元素
SLDataType StackTop(Stack* ps);
//栈中有效数据范围
int StackSize(Stack* ps);
//检测栈是否为空
bool StackEmpty(Stack* ps);
//栈销毁
void StackDestory(Stack* ps);