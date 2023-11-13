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

ListNode* ListCreate(LTDataType x);//创建双向链表节点
ListNode* ListInit();//初始化头节点
void ListPushBack(ListNode * plist, LTDataType x);//尾插双向链表节点
void ListPopBack(ListNode* plist);//尾删双向链表节点
void ListPushFront(ListNode* plist, LTDataType x);//头插双向链表节点
void ListPopFront(ListNode* plist);//头删双向链表节点
ListNode* ListFind(ListNode* plist, LTDataType x);//双向链表查找
void ListInsert(ListNode* plist, ListNode* pos, LTDataType x);//在pos前插入数据
void ListErase(ListNode* plist, ListNode* pos);//删除pos位置的节点
void ListPrint(ListNode* plist);//双向链表打印
void ListDestory(ListNode* plist);//双向链表销毁