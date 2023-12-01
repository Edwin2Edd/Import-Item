#define  _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include "BinaryTree.h"


//通过前序遍历数据生成二叉树
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

//二叉树节点个数
int BinaryTreeSize(BTNode* pheap) {
	if (pheap == NULL)
		return 0;
	return BinaryTreeSize(pheap->left) + BinaryTreeSize(pheap->right) + 1;
}

//二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* pheap) {
	if (pheap == NULL)
		return 0;
	if (!pheap->left && !pheap->right)
		return 1;
	return BinaryTreeLeafSize(pheap->left) + BinaryTreeLeafSize(pheap->right);
}

//二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* pheap, int k) {
	assert(k > 0);
	if (pheap == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(pheap->left, k - 1) + BinaryTreeLevelKSize(pheap->right, k - 1);
}

//二叉树的高度
int BinaryTreeHeight(BTNode* pheap) {
	int left_h = 0, right_h = 0;
	if (pheap == NULL)
		return 0;
	left_h = BinaryTreeHeight(pheap->left);
	right_h = BinaryTreeHeight(pheap->right);
	return left_h > right_h ? left_h + 1 : right_h + 1;
}

//查找值为x的节点
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

//二叉树前序遍历
void BinaryTreePrevOrder(BTNode* pheap) {
	if (!pheap) {
		printf("# ");
		return;
	}
	printf("%c ", pheap->val);
	BinaryTreePrevOrder(pheap->left);
	BinaryTreePrevOrder(pheap->right);
}

//二叉树中序遍历
void BinaryTreeInOrder(BTNode* pheap) {
	if (!pheap) {
		printf("# ");
		return;
	}
	BinaryTreeInOrder(pheap->left);
	printf("%c ", pheap->val);
	BinaryTreeInOrder(pheap->right);
}

//二叉树后序遍历
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
////数据入队
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
////层序遍历
//void BinaryTreeLevelOrder(BTNode* root) {
//	Queue p;
//	QListInit(&p);
//	QListPush(&p, root->val);
//	TreeValIntoQueue(root, &p);
//	
//	QListDestory(&p);
//}

//层序遍历
void BinaryTreeLevelOrder(BTNode* root) {
	Queue p;
	QListInit(&p);
	QListPush(&p, root->val);
	if (root != NULL)
		QListPush(&p, root);


}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root) {
	if (!root)
		return true;
	return BinaryTreeComplete(root->left) && BinaryTreeComplete(root->right);
}

//销毁二叉树
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