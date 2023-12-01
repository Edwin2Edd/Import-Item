#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int SLDataType;

typedef struct Stack {
	SLDataType* a;
	int top;//ջ��
	int capacity;//����
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps);  
//��ջ
void StackPush(Stack* ps, SLDataType x);
//��ջ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
SLDataType StackTop(Stack* ps);
//ջ����Ч���ݷ�Χ
int StackSize(Stack* ps);
//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps);
//ջ����
void StackDestory(Stack* ps);