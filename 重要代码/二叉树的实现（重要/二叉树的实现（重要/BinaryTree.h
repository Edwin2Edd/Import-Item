#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef char BTDatatype;

typedef struct BinaryTreeNode {
	BTDatatype val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//通过前序遍历数组数据生成二叉树
BTNode* BinaryTreeCreate(BTDatatype* arr, int arr_size ,int *p);
//二叉树节点个数
int BinaryTreeSize(BTNode* pheap);
//二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* pheap);
//二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* pheap, int k);
//二叉树的高度
int BinaryTreeHeight(BTNode* pheap);
//查找值为x的节点
BTNode* BinaryTreeFindNode(BTNode* pheap, BTDatatype x);
//二叉树前序遍历
void BinaryTreePrevOrder(BTNode* pheap);
//二叉树中序遍历
void BinaryTreeInOrder(BTNode* pheap);
//二叉树后序遍历
void BinaryTreePostOrder(BTNode* pheap);
//层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);
//销毁二叉树
void BinaryTreeDestory(BTNode** pheap);