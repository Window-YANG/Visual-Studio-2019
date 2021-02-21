#include "¶þ²æÊ÷.h"

Binary_Node* InitBitNode(char String)
{
	Binary_Node* Node = (Binary_Node*)malloc(sizeof(Binary_Node));
	assert(Node);
	Node->data = String;
	Node->LChild = NULL;
	Node->RChild = NULL;
	return Node;
}

Binary_Tree CreatBitTree(Binary_Tree Tree, char String1, char String2, char String3)
{
	
	Tree = InitBitNode(String1);
	if (String2 == NULL)
		return Tree;
	if (String3 == NULL)
		return Tree;
	Tree->LChild = CreatBitTree(Tree,String2,NULL,NULL);
	Tree->RChild = CreatBitTree(Tree, String3, NULL, NULL);

	return Tree;
}

int PreOrderBitTree(Binary_Tree Tree)
{
	if (Tree == NULL)
		return 0;
	else
	{
		printf("%c\n", Tree->data);
		PreOrderBitTree(Tree->LChild);
		PreOrderBitTree(Tree->RChild);
	}
}

int InOrderBitTree(Binary_Tree Tree)
{
	if (Tree == NULL)
		return 0;
	else
	{
		InOrderBitTree(Tree->LChild);
		printf("%c\n", Tree->data);
		InOrderBitTree(Tree->RChild);
	}
}

int PostOrderBitTree(Binary_Tree Tree)
{
	if (Tree == NULL)
		return 0;
	else
	{
		InOrderBitTree(Tree->LChild);
		InOrderBitTree(Tree->RChild);
		printf("%c\n", Tree->data);
	}
}

int CountNodes(Binary_Tree Tree)
{
	if (Tree == NULL)
		return 0;
	else
	{
		return CountNodes(Tree->LChild) + CountNodes(Tree->RChild) + 1;
	}
}

int CountTreeDeep(Binary_Tree Tree)
{
	if (Tree == NULL)
		return 0;
	else
	{
		return (CountTreeDeep(Tree->LChild) > CountTreeDeep(Tree->RChild) ? \
			CountTreeDeep(Tree->LChild) : CountTreeDeep(Tree->RChild)) + 1;

	}
}

int CountLeaves(Binary_Tree Tree)
{
	if (Tree == NULL)
		return 0;
	if (Tree->LChild == NULL && Tree->RChild == NULL)
		return 1;
	return CountLeaves(Tree->LChild) + CountLeaves(Tree->RChild);
}