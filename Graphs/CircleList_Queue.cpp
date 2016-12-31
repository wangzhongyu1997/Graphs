#include "CircleList_Queue.h"



CircleList_Queue::CircleList_Queue()
{
	rear = nullptr;
	n = 0;
}

CircleList_Queue::CircleList_Queue(int)
{
}


CircleList_Queue::~CircleList_Queue()
{
	clear();
}

void CircleList_Queue::in(Element d)
{
	if (!n)
	{
		rear = new node;
		rear->data = d;
		rear->next = rear;
		n++;
	}
	else
	{
		node*NewN = new node;
		NewN->next = rear->next;
		NewN->data = d;
		rear->next = NewN;
		rear = NewN;
		n++;
	}
}

Element CircleList_Queue::out()
{
	if (n == 1)
	{
		Element t = rear->data;
		delete rear;
		rear = nullptr;
		n--;
		return  t;
	}
	node*p = rear->next;
	rear->next = rear->next->next;
	Element t = p->data;
	delete p;
	n--;
	return t;
}

bool CircleList_Queue::isEmpty()
{
	return !bool(n);
}

void CircleList_Queue::display()
{
	node*p = rear->next;
	while (p!=rear)
	{
		std::cout << p->data << ' ';
		p = p->next;
	}
	std::cout << p->data << ' ';
}

void CircleList_Queue::clear()
{
	if (n)
	{
		while (rear->next != rear)
		{
			node*p = rear->next;
			rear->next = rear->next->next;
			delete p;
		}
		delete rear;
		rear = nullptr;
		n = 0;
	}
}
