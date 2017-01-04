#include "auto_queue.h"



int auto_queue::deQueue()
{
	std::multimap<double, int>::iterator it = this->begin();
	int index = (*it).second;
	this->erase(it);
	return index;
}

void  auto_queue::enQueue(std::pair<double, int> &NewEle)
{
	this->insert(NewEle);
}

auto_queue::auto_queue()
{
}


auto_queue::~auto_queue()
{
}
