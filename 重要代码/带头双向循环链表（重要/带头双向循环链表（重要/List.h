#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode {
	LTDataType* val;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

ListNode* ListCreate(LTDataType x);//����˫������ڵ�
ListNode* ListInit();//��ʼ��ͷ�ڵ�
void ListPushBack(ListNode * plist, LTDataType x);//β��˫������ڵ�
void ListPopBack(ListNode* plist);//βɾ˫������ڵ�
void ListPushFront(ListNode* plist, LTDataType x);//ͷ��˫������ڵ�
void ListPopFront(ListNode* plist);//ͷɾ˫������ڵ�
ListNode* ListFind(ListNode* plist, LTDataType x);//˫���������
void ListInsert(ListNode* plist, ListNode* pos, LTDataType x);//��posǰ��������
void ListErase(ListNode* plist, ListNode* pos);//ɾ��posλ�õĽڵ�
void ListPrint(ListNode* plist);//˫�������ӡ
void ListDestory(ListNode* plist);//˫����������