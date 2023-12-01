#define  _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include "BinaryTree.h"

int main() {
	char arr[] = "ABD##E#H##CF##G##";
	int start = 0;
	BTNode* phead = BinaryTreeCreate(arr, sizeof(arr) / sizeof(arr[0]),&start);
	printf("TreeSize = %d\n", BinaryTreeSize(phead));
	printf("TreeLeafSize = %d\n", BinaryTreeLeafSize(phead));
	printf("TreeLevelKSize = %d\n", BinaryTreeLevelKSize(phead, 2));
	printf("TreeHeight = %d\n", BinaryTreeHeight(phead));
	BTNode* FineNode = BinaryTreeFindNode(phead, 'C');
	assert(FineNode);
	printf("FineNode : %p \n", FineNode);
	printf("TreePrevOrder:");
	BinaryTreePrevOrder(phead);
	printf("\n");
	printf("TreeINOrder:");
	BinaryTreeInOrder(phead);
	printf("\n");
	printf("TreePostOrder:");
	BinaryTreePostOrder(phead);
	printf("\n");
	printf("TreeLevelOrder:");
	BinaryTreeLevelOrder(phead);
	printf("\n");
	BinaryTreeDestory(&phead);
}