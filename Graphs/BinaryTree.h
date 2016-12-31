#pragma once
#include<string>
#include"CircleList_Queue.h"


typedef std::string  Type;

 struct BinaryNode
{
	 BinaryNode* leftChild;
	 BinaryNode*rightChild;
	 Type data;
	 BinaryNode();
};
 typedef BinaryNode* BinaryTree;

 BinaryTree creat_tree_for_cin();
 BinaryTree creat_tree_for_queue(CircleList_Queue&TheQueue);

 void insert_sort(BinaryTree&T,Type&e);
 void visit(BinaryTree T, void(Visit(BinaryNode*)));
