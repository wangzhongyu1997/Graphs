#pragma once
#include<map>
class auto_queue:public  std::multimap<double,int>
{
public:
	int deQueue();
	void enQueue(std::pair<double, int>&NewEle);
	auto_queue();
	~auto_queue();
};

