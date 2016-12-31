#include "BinaryTree.h"
#include<iostream>
//#include<cstring>
BinaryTree creat_tree_for_cin()
{
	Type temp;
	std::cin >> temp;
	if (temp != "#")
	{
		BinaryTree newTree = new BinaryNode;
		newTree->data = temp;
		newTree->leftChild = creat_tree_for_cin();
		newTree->rightChild = creat_tree_for_cin();
		return newTree;
	}
	else
	{
		return nullptr;
	}

}

BinaryTree creat_tree_for_queue(CircleList_Queue & TheQueue)
{
	Type temp;
	temp=TheQueue.out();
	if (temp != " ")
	{
		BinaryTree newTree = new BinaryNode;
		newTree->data = temp;
		newTree->leftChild = creat_tree_for_queue(TheQueue);
		newTree->rightChild = creat_tree_for_queue(TheQueue);
		return newTree;
	}
	else
	{
		return nullptr;
	}

}




void insert_sort(BinaryTree & T, Type& e)
{
	if (!T)
	{
		T = new BinaryNode;
		T->data = e;
		T->leftChild = T->rightChild = nullptr;
	}
	else if(e<T->data)
	{
		insert_sort(T->leftChild, e);
	}
	else
	{
		insert_sort(T->rightChild, e);
	}
}

void visit(BinaryTree T, void (Visit(BinaryNode *)))
{
	if (T)
	{
		Visit(T);
		visit(T->leftChild, Visit);
		visit(T->rightChild, Visit);
	}
}

BinaryNode::BinaryNode()
{
	this->leftChild = nullptr;
	this->rightChild = nullptr;
}
