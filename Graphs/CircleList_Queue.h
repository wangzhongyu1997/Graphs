#pragma once
#include<iostream>
//#include<string>
typedef int Element;
struct node
{
	Element data;
	node*next;
};



class CircleList_Queue
{
public:
	CircleList_Queue();
	CircleList_Queue(int );
	~CircleList_Queue();

	void in(Element d);
	Element out();
	void clear();

	bool isEmpty();
	void display();
private:
	node *rear;
	int n;//记录节点数
};

