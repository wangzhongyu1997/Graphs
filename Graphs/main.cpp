#include"Graph.h"
#include<iostream>
#include"CircleList_Queue.h"
#include"Graph_matrix.h"
#include"BinaryTree.h"
void set(std::string&a)
{
	std::cin >> a;
}
void visit(Vnode &a)
{
	std::cout << a.data<<std::endl;
}

int main()
{
	/**
	*ע�⣬�����������߼���ڽӾ����Ƿ������ڽӱ�ġ� 
	*��Ϊ�����洢��ʽ��ͬ���Ұ����Ƿ��ڲ�ͬ���������ָ��ۺϡ����쿴��
	*���⣬��ɾ��һ����ʱ����������������䣬�˵㱻���Ϊɾ������ɾ����֮�ڽӵ����л����ڽӱ�//���߰���֮�ڽӵ����л���Ȩ���Ϊ-1(�ڽӾ���)
	*��num_V���ֲ���
	*/
	int V = 6;
	int E = 8;
	//Graph gg(6, 8);//will create a graph completely with cin
	Graph gg(set);
	BinaryTree tree=nullptr;
//	gg.DFS_createBinaryTree(0, tree);
	gg.DFS(visit, 0);
	gg.refresh();
	std::cout << std::endl;
	gg.BFS(visit, 0);
	Graph_matrix*graph = gg.New_get_matrix();//��ȡ����
	std::string path;
	
	path=graph->closest_to(0, 5);
	std::cout << path<<std::endl;
	gg.del_V(gg._locate("V4"));
	path = graph->closest_to(0, 5);
	std::cout << path;
	delete graph;
	
	return 0;
}