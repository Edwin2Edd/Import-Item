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

//��ջ
void StackPush(st** plist, STDatatype x);

//��ջ
void StackPop(st** plist);

//��ȡջ��Ԫ��
STDatatype StackTop(st* plist);

//��ȡջ�е���Ч����
int StackSize(st* plist);

//��ӡջ
void StackPrint(st* plist);

//���ջ�Ƿ�Ϊ��
bool StackEmpty(st* plist);

//����ջ
void StackDestroy(st** plist);
