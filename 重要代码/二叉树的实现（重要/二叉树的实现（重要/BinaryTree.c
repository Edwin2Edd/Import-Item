#define  _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include "BinaryTree.h"


//ͨ��ǰ������������ɶ�����
BTNode* BinaryTreeCreate(BTDatatype* arr, int arr_size, int* start) {
	
	if (arr == NULL || arr_size <= 0) {
		return;
	}
	if (arr[*start] == '#') {
		(*start)++;
		return NULL;
	}
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->val = arr[*start];
	
	(*start)++;
	newnode->left = BinaryTreeCreate(arr, arr_size, start);
	newnode->right = BinaryTreeCreate(arr, arr_size, start);
	return newnode;
}

//�������ڵ����
int BinaryTreeSize(BTNode* pheap) {
	if (pheap == NULL)
		return 0;
	return BinaryTreeSize(pheap->left) + BinaryTreeSize(pheap->right) + 1;
}

//������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* pheap) {
	if (pheap == NULL)
		return 0;
	if (!pheap->left && !pheap->right)
		return 1;
	return BinaryTreeLeafSize(pheap->left) + BinaryTreeLeafSize(pheap->right);
}

//��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* pheap, int k) {
	assert(k > 0);
	if (pheap == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(pheap->left, k - 1) + BinaryTreeLevelKSize(pheap->right, k - 1);
}

//�������ĸ߶�
int BinaryTreeHeight(BTNode* pheap) {
	int left_h = 0, right_h = 0;
	if (pheap == NULL)
		return 0;
	left_h = BinaryTreeHeight(pheap->left);
	right_h = BinaryTreeHeight(pheap->right);
	return left_h > right_h ? left_h + 1 : right_h + 1;
}

//����ֵΪx�Ľڵ�
BTNode* BinaryTreeFindNode(BTNode* pheap, BTDatatype x) {
	BTNode* p = NULL;
	if (pheap == NULL)
		return NULL;
	if (pheap->val == x)
		return pheap;
	p = BinaryTreeFindNode(pheap -> left, x);
	if (p != NULL)
		return p;
	p = BinaryTreeFindNode(pheap->right, x);
	if (p != NULL)
		return p;
}

//������ǰ�����
void BinaryTreePrevOrder(BTNode* pheap) {
	if (!pheap) {
		printf("# ");
		return;
	}
	printf("%c ", pheap->val);
	BinaryTreePrevOrder(pheap->left);
	BinaryTreePrevOrder(pheap->right);
}

//�������������
void BinaryTreeInOrder(BTNode* pheap) {
	if (!pheap) {
		printf("# ");
		return;
	}
	BinaryTreeInOrder(pheap->left);
	printf("%c ", pheap->val);
	BinaryTreeInOrder(pheap->right);
}

//�������������
void BinaryTreePostOrder(BTNode* pheap) {
	if (!pheap) {
		printf("# ");
		return;
	}
	BinaryTreePostOrder(pheap->left);
	BinaryTreePostOrder(pheap->right);
	printf("%c ", pheap->val);
}
//
////�������
//void TreeValIntoQueue(BTNode* root, Queue* p) {
//	if (root == NULL)
//		return;
//	printf("%c", QueueFront(p));
//	QListPop(p);
//	if (root->left)
//		QListPush(p, root->left->val);
//	if (root->right)
//		QListPush(p, root->right->val);
//	TreeValIntoQueue(root->left,p);
//	TreeValIntoQueue(root->right,p);
//}
//
////�������
//void BinaryTreeLevelOrder(BTNode* root) {
//	Queue p;
//	QListInit(&p);
//	QListPush(&p, root->val);
//	TreeValIntoQueue(root, &p);
//	
//	QListDestory(&p);
//}

//�������
void BinaryTreeLevelOrder(BTNode* root) {
	Queue p;
	QListInit(&p);
	QListPush(&p, root->val);
	if (root != NULL)
		QListPush(&p, root);


}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root) {
	if (!root)
		return true;
	return BinaryTreeComplete(root->left) && BinaryTreeComplete(root->right);
}

//���ٶ�����
void BinaryTreeDestory(BTNode** pheap) {
	if ((*pheap) == NULL) {
		return;
	}
	if (!(*pheap)->left && !(*pheap)->right) {
		free(*pheap);
		*pheap = NULL;
		return;
	}
	BinaryTreeDestory(&(*pheap)->left); 
	BinaryTreeDestory(&(*pheap)->right);
	if (!(*pheap)->left && !(*pheap)->right) {
		free(*pheap);
		*pheap = NULL;
		return;
	}
}