#pragma once
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef struct
{
	struct Binary_Node* LChild;
	struct Binary_Node* RChild;
	char data;
}*Binary_Tree, Binary_Node;


Binary_Node* InitBitNode(char String);
Binary_Tree CreatBitTree(Binary_Tree Tree, char String1, char String2, char String3);
int PreOrderBitTree(Binary_Tree Tree);
int InOrderBitTree(Binary_Tree Tree);
int PostOrderBitTree(Binary_Tree Tree);
int CountNodes(Binary_Tree Tree);
int CountTreeDeep(Binary_Tree Tree);
int CountLeaves(Binary_Tree Tree);