#include "Graph_matrix.h"
#include<iostream>
#include"Graph.h"
#include<string> 

extern const int MAX = INT_MAX;

Graph_matrix::Graph_matrix(int n):_n(n)
{
	relative = nullptr;
	this->init();
}

void Graph_matrix::dij_path(int index)
{
	for (int i = 0; i < _n; i++)
	{
		distance[i] = table[index][i];//distance[i]表示从  index到 i 的距离
		if (table[index][i] < MAX)
			path[i] = index;
		else path[i] = -1;

	}
	Selected[index] = true;
	distance[index] = 0;
	//初始化完成

	int index_of_selected=-2;
	for (int i = 1; i < _n; i++)//最外层循环，记录次数
		{
			int min = MAX;

			for(int j=0;j<_n;j++)
			if (distance[j]!=-1&&!Selected[j] && distance[j] < min)//从V集合中选取一个点//(V=U-S)
																						//distance[j]!=-1，distance[j]为-1时表示 首尾 至少有一个点被删除
			{
				min = distance[j];
				index_of_selected = j;
			}

			if (index_of_selected == -2)//此点到每一个点的距离都是-1
				throw std::range_error("起点被删除");

			Selected[index_of_selected] = true;//只要被选择了，那它的前驱一定就明确了



			//下面是更新distance[j]数组
										//把V中元素的distance改掉,并修改j的前驱，注意
										//既然已经把index_of_selected选了进来，说明 index 到 index_of_selected是可到达的
										//没必要考虑index. . .index_of_selected.中   .index_of_selected 的可达性（这是在上一步的 此处 处理好的）
										//只有可能是 j的前驱不明确，不可能是j 的前驱 的前驱不明确（假设in that case ,它将会在这一步之前被处理掉）
			for (int j = 0; j < _n; j++)
				if (!Selected[j] &&
					(distance[j] >0.0+ distance[index_of_selected] + table[index_of_selected][j])//0.0+作用是自动类型转换，因为后边两个整数相加可能超过INT_MAX会 转为负值
					)
				{
					distance[j] = distance[index_of_selected] + table[index_of_selected][j];
					path[j] = index_of_selected;
				}
		}
}

void Graph_matrix::refesh_selected()
{
	for (int i = 0; i < _n; i++)
	{
		Selected[i] = false;
	}
}

void Graph_matrix::init()
{
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j <_n; j++)
			table[i][j] = MAX;

		Selected[i] = false;
	}
}


void Graph_matrix::setValue(Graph*gp)
{
	this->init();
	relative = gp;
	_n = gp->num_V;
	for (int i = 0; i < _n; i++)
	{
		ArcNode*p = gp->list[i].firstArc;
		while (p)
		{
			table[i][p->ToV] = p->info;
			p = p->nearArc;
		}
	}

}

void Graph_matrix::add_E(int from, int des,int coast)
{
	if(relative)
		relative->add_E(from, des, coast);
	else
	{
		table[from][des] = coast;
	}
}

void Graph_matrix::add_V(Data d)
{
	if (relative)
		relative->add_V(d);
	else
	{
		for (int i = 0; i <= _n; i++)
		{
			table[_n][i] = MAX;
			table[i][_n] = MAX;
		}
		_n++;
	}
}

void Graph_matrix::del_E(int from, int des)
{
	if (relative)
		relative->del_E(from, des);
	else
	{
		table[from][des] = MAX;
	}
}

void Graph_matrix::del_V(int index)
{
	if (relative)
		relative->del_V(index);
	else
	{
		for (int i = 0; i < _n; i++)
		{
			table[index][i] = -1;
			table[i][index] = -1;
		}
	}
}

std::string Graph_matrix::closest_to(int first,int destination)
{
	this->refesh_selected();//重置S集合
	int p = destination;
	this->dij_path(first);
	std::string route="";
	do
	{
		route ="->"+   relative->list[p].data + route;
		p = path[p];
	} while (p!=first);

	route = relative->list[first].data + route;
	return route;
}


Graph_matrix::Graph_matrix(Graph_matrix & another)
{
	

	relative = another.relative;
	_n = another._n;
	this->init();
	for (int i = 0; i < _n; i++)
	{
		path[i] = another.path[i];
		Selected[i] = another.Selected[i];
		distance[i] = another.distance[i];
	}

	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _n; j++)
			table[i][j] = another.table[i][j];
	}
}


Graph_matrix::~Graph_matrix()
{
	
}
