#pragma once
#include<string>
typedef  std::string Data;

class Graph;
class Graph_matrix
{
public:
	friend class Graph;

	std::string closest_to(int first, int destination);
	void dij_path(int index);

	void init();//置table为全不可达
	void setValue(Graph*gp);
	int path[30];//某个节点前驱 用于dij_sort
	void add_E(int from,int des,int coast);
	void add_V(Data d);
	void del_E(int from, int des);
	void del_V(int index);

	
private:
	Graph_matrix(int n);
	int _n;//规模
	int table[30][30];//表//////////////////////*没有用动态数组，因为规模已知，避免再次分配空间
	int distance[30];//用于 dij_sort
	bool  Selected[30];//用于 dij_sort
	Graph*relative;//与之相关联的图(邻接表)
};

