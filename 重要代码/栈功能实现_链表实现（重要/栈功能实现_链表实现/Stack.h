#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDatatype;

typedef struct Stack
{
	STDatatype val;
	struct Stack* next;
}st;

//入栈
void StackPush(st** plist, STDatatype x);

//出栈
void StackPop(st** plist);

//获取栈顶元素
STDatatype StackTop(st* plist);

//获取栈中的有效数据
int StackSize(st* plist);

//打印栈
void StackPrint(st* plist);

//检测栈是否为空
bool StackEmpty(st* plist);

//销毁栈
void StackDestroy(st** plist);
