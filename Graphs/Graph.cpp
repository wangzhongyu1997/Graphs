#include "Graph.h"
#include<iostream>
#include<stdexcept>
#include"CircleList_Queue.h"
#include"Graph_matrix.h"
#include"BinaryTree.h"
extern const  int MAX;

void Graph::DFS(void visit(Vnode &),int v)//��ͨͼ��DFS
{
	visit(list[v]);
	visited[v] = true;
	ArcNode*p = list[v].firstArc;
	while (p)
	{
		int w = p->ToV;
		if (!visited[w]) DFS(visit, w);
		p = p->nearArc;
	}
}
void Graph::DFS(int v)
{
	visited[v] = true;
	ArcNode*p = list[v].firstArc;
	while (p)
	{
		int w = p->ToV;
		if (!visited[w]) DFS(w);
		p = p->nearArc;
	}
}
void Graph::DFS_createBinaryTree(int v, BinaryNode *& T)
{
	//visit(list[v]);
	visited[v] = true;
	T = new BinaryNode;
	T->data = list[v].data;
	right = false;

	ArcNode*p = list[v].firstArc;
	while (p)
	{
		int w = p->ToV;
		if (!visited[w]&&!right) DFS_createBinaryTree(w,T->leftChild);
		
		if (!visited[w] &&right)DFS_createBinaryTree(w, T->rightChild);
		
		p = p->nearArc;
		right = true;
	}
}

void Graph::BFS(void visit(Vnode&),int v)//��ͨͼ��BFS
{
	visit(list[v]);
	visited[v] = true;

	CircleList_Queue pre_of_ToBeVisited;//��ŷ��ʹ��ĵ㣬��δ���ʵ��ǰ��
	pre_of_ToBeVisited.in(v);
	int temp;
	while (!pre_of_ToBeVisited.isEmpty())
	{
		temp = pre_of_ToBeVisited.out();
		for (ArcNode *arc = list[temp].firstArc; arc; arc=arc->nearArc)
		{
			int index = arc->ToV;
			if (!visited[index])
			{
				visit(list[index]);
				visited[index] = true;
				pre_of_ToBeVisited.in(index);
			}
		}
	}
}
void Graph::BFS2(void visit(Vnode&), int v)
{
	visit(list[v]);
	visited[v] = true;
	//CircleList_Queue pre_of_ToBeVisited();//��ŷ��ʹ��ĵ㣬��δ���ʵ��ǰ��
}
std::string Graph::closest_to(int first, int destination)
{
	if(relative)
		return relative->closest_to(first, destination);
	else
	{
		throw std::overflow_error("û��relative,�޷�����");
	}
}
void Graph::refresh_visited()
{
	for (int i = 0; i < num_V; i++)
	{
		visited[i] = false;
	}
}
void Graph::add_V(Data d)
{
	list[num_V].data = d;
	list[num_V].firstArc = nullptr;
	num_V++;
	if (relative)
	{
		int n = relative->_n;
		for (int i = 0; i <= n; i++)
		{
			relative->table[n][i] = MAX;
			relative->table[i][n] = MAX;
		}
		relative->_n++;
	}
}
void Graph::add_E(int from, int des,int coast)
{
	ArcNode*NewArc = new ArcNode;
	NewArc->ToV = des;
	NewArc->info = coast;
	NewArc->nearArc = list[from].firstArc;
	list[from].firstArc = NewArc;
	if (relative)
		relative->table[from][des] = coast;
}

bool Graph::del_E(int from, int des)
{
	ArcNode *pre = list[from].firstArc;
	if (!pre)
		return false;

	ArcNode *p = pre->nearArc;
	if (pre->ToV == des)
	{
		delete pre;
		list[from].firstArc = p;

		if (relative)
			relative->table[from][des] = MAX;

		return true;
	}
	else
	{
		while (p&&p->ToV!=des)
		{
			pre = p;
			p = p->nearArc;
		}
		if (p->ToV == des)
		{
			pre->nearArc = p->nearArc;
			delete p;

			if (relative) 
				relative->table[from][des] = MAX;

			return true;
		}
		else return false;
	}

}

void Graph::del_V(int index)
{
	if(list[index].data!="")
	{
		list[index].data = "";
		ArcNode*p = list[index].firstArc;
		list[index].firstArc = nullptr;
		ArcNode*temp = p;
		while (p)
		{
			temp = p;
			p = p->nearArc;
			delete temp;
		}
		for (int i = 0; i < num_V; i++)
		{
			if (list[i].data == "")//�˵��Ѿ���ɾ��
				continue;

			ArcNode *pre = list[i].firstArc;

			if (!pre)//�˵�û�г���
				continue;

			if (pre->ToV == index)
			{
				list[i].firstArc = list[i].firstArc->nearArc;
				delete pre;
			}
			else
			{
				ArcNode *now = pre->nearArc;
				while (now)
				{
					if (now->ToV == index)
					{
						pre->nearArc = now->nearArc;
						delete now;
						now = pre->nearArc;
						continue;
					}
					pre = now;
					now = now->nearArc;
				}
			}
		}


		if (relative)
		{
			int n = relative->_n;
			for (int i = 0; i < n; i++)
			{
				relative->table[index][i] = -1;
				relative->table[i][index] = -1;
			}
		}
	}
}

Graph::Graph(void set(Data&Element))
{
	right = false;
	relative = nullptr;
	std::cout << "��������ͼ������ڵ����ͱ���\n>";
	std::cin >> num_V >> num_E;//����ڵ����ͱ���
	visited = new bool[num_V];
	for (int i = 0; i < num_V; i++)
	{
		visited[i] = false;
	}
	std::cout << "�����ڵ�" << std::endl;
	for (int i = 0; i < num_V; i++)
	{
		set(list[i].data);
		list[i].firstArc = nullptr;
	}
	std::cout << "�����:(��)�׽ڵ㣬β�ڵ㣻  (int)Ȩֵ\n";
	Data first, second;
	int cost;
	for (int i = 0; i < num_E; i++)
	{
		std::cout << '>';
		std::cin >> first >> second>>cost;
		int index_1 = _locate(first);
		int index_2 = _locate(second);
		ArcNode *ArcNew = new ArcNode;
		ArcNew->info = cost;
		ArcNew->ToV = index_2;//��first-��second
		ArcNew->nearArc = list[index_1].firstArc;
		list[index_1].firstArc = ArcNew;

		ArcNode*ArcNew2 = new ArcNode;
		ArcNew2->info = cost;
		ArcNew2->nearArc = list[index_2].firstArc;
		ArcNew2->ToV = index_1;//��second-��first
		list[index_2].firstArc = ArcNew2;
	}
}

Graph::Graph(int Vnum, int Enum)
{	
	right = false;
	relative = nullptr;
	num_V = Vnum;
	num_E = Enum;
	visited = new bool[num_V];
	for (int i = 0; i < num_V; i++)
	{
		visited[i] = false;
	}
	std::cout << "�����ڵ�" << std::endl;
	for (int i = 0; i < num_V; i++)
	{
		std::cin>>list[i].data;
		list[i].firstArc = nullptr;
	}
	std::cout << "�����:(��)������㣬�����յ㣬  (int)Ȩֵ\n";
	Data first, second;
	int cost;
	for (int i = 0; i < num_E; i++)
	{
		std::cout << '>';
		std::cin >> first >> second >> cost;
		int index_1 = _locate(first);
		int index_2 = _locate(second);
		ArcNode *ArcNew = new ArcNode;
		ArcNew->info = cost;
		ArcNew->ToV = index_2;//��first-��secondָ��second
		ArcNew->nearArc = list[index_1].firstArc;
		list[index_1].firstArc = ArcNew;

	}
}

Graph_matrix* Graph::New_get_matrix()
{
	Graph_matrix* graph=new Graph_matrix(num_V);
	for (int i = 0; i < num_V; i++)
	{
		ArcNode*p = list[i].firstArc;
		while (p)
		{
			graph->table[i][p->ToV] = p->info;
			p = p->nearArc;
		}
	}
	graph->relative = this;
	this->relative = graph;
	return graph;
}


Graph::~Graph()
{
	for (int i = 0; i < num_V; i++)
	{
		ArcNode*pre = list[i].firstArc;
		if (!pre)
			continue;
		ArcNode * p = pre->nearArc;
		while (p)
		{
			delete pre;
			pre = p;
			p = p->nearArc;
		}
		delete pre;
	}
	//delete[]list; list�Ǿ�̬��
	if (relative)
		delete relative;
}

int Graph::_locate(const Data& e)
{
	for (int i = 0; i < num_V; i++)
		if (list[i].data == e)
			return i;
	throw std::range_error("û�ҵ�����");
}
