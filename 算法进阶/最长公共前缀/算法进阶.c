#include "最长公共前缀.h"
#include "二叉树.h"
int main(void)
{
	//longestCommonPrefix();

	Binary_Tree tree; Binary_Node node;
	tree = &node;
	tree = CreatBitTree(tree, 'A', 'B', 'C');
	PreOrderBitTree(tree);

	return 0;
}

