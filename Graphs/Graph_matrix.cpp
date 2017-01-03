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
		distance[i] = table[index][i];//distance[i]��ʾ��  index�� i �ľ���
		if (table[index][i] < MAX)
			path[i] = index;
		else path[i] = -1;

	}
	Selected[index] = true;
	distance[index] = 0;
	//��ʼ�����

	int index_of_selected=-2;
	for (int i = 1; i < _n; i++)//�����ѭ������¼����
		{
			int min = MAX;

			for(int j=0;j<_n;j++)
			if (distance[j]!=-1&&!Selected[j] && distance[j] < min)//��V������ѡȡһ����//(V=U-S)
																						//distance[j]!=-1��distance[j]Ϊ-1ʱ��ʾ ��β ������һ���㱻ɾ��
			{
				min = distance[j];
				index_of_selected = j;
			}

			if (index_of_selected == -2)//�˵㵽ÿһ����ľ��붼��-1
				throw std::range_error("��㱻ɾ��");

			Selected[index_of_selected] = true;//ֻҪ��ѡ���ˣ�������ǰ��һ������ȷ��



			//�����Ǹ���distance[j]����
										//��V��Ԫ�ص�distance�ĵ�,���޸�j��ǰ����ע��
										//��Ȼ�Ѿ���index_of_selectedѡ�˽�����˵�� index �� index_of_selected�ǿɵ����
										//û��Ҫ����index. . .index_of_selected.��   .index_of_selected �Ŀɴ��ԣ���������һ���� �˴� ����õģ�
										//ֻ�п����� j��ǰ������ȷ����������j ��ǰ�� ��ǰ������ȷ������in that case ,����������һ��֮ǰ���������
			for (int j = 0; j < _n; j++)
				if (!Selected[j] &&
					(distance[j] >0.0+ distance[index_of_selected] + table[index_of_selected][j])//0.0+�������Զ�����ת������Ϊ�������������ӿ��ܳ���INT_MAX�� תΪ��ֵ
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
	this->refesh_selected();//����S����
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
