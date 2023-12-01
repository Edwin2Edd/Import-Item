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

//ͨ��ǰ����������������ɶ�����
BTNode* BinaryTreeCreate(BTDatatype* arr, int arr_size ,int *p);
//�������ڵ����
int BinaryTreeSize(BTNode* pheap);
//������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* pheap);
//��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* pheap, int k);
//�������ĸ߶�
int BinaryTreeHeight(BTNode* pheap);
//����ֵΪx�Ľڵ�
BTNode* BinaryTreeFindNode(BTNode* pheap, BTDatatype x);
//������ǰ�����
void BinaryTreePrevOrder(BTNode* pheap);
//�������������
void BinaryTreeInOrder(BTNode* pheap);
//�������������
void BinaryTreePostOrder(BTNode* pheap);
//�������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);
//���ٶ�����
void BinaryTreeDestory(BTNode** pheap);