#include"Graph.h"
#include<iostream>
//#include"CircleList_Queue.h"
#include"Graph_matrix.h"
#include"BinaryTree.h"
void set(std::string&a)
{
	std::cin >> a;
}
void visit(Vnode &a)
{
	std::cout << a.data << ' ';
}

int main()
{
	/**
	*ע�⣬�����������߼���ڽӾ����Ƿ������ڽӱ�ġ� 
	*��Ϊ�����洢��ʽ��ͬ���Ұ����Ƿ��ڲ�ͬ���������ָ��ۺϡ�

	*�ڽӾ��󲻱���Data
	*���ò�˵��д�ĺ��ң��ұ���д�ܶ�ע���������ϵ

	Graph_matrix:
	
	dij_path(int index);//�޽����˹�㷨

	refesh();//���ü���S���Ա�   �ٴ�ʹ�õ޽�����˹�㷨
	init();//��tableΪȫ���ɴ�
	setValue(Graph*gp);

	string closest_to(int first, int destination);*****************
	add_E(int from,int des,int coast);**************************
	add_V(Data d);**��������������������໥�����������ȼ�*
	del_E(int from, int des);***********************************
	del_V(int index);******************************************

	Graph��
	DFS(void visit(Vnode&),int v);
	DFS_createBinaryTree( int v, BinaryNode* &T);
	BFS(void visit(Vnode&),int v);
	BFS2(void visit(Vnode&), int v);
	refresh();//Ϊ������ʰ��̯�ӣ��Ա���һ������
	
	std::string closest_to(int first, int destination);************
	add_V(Data d);*******************************************
	add_E(int from,int des,int coast);*************************
	del_E(int from,int des);***********************************
	del_V(int index);*****************************************


	*���⣬��ɾ��һ����ʱ����������������䣬�˵㱻���Ϊɾ������ɾ����֮�ڽӵ����л����ڽӱ�//���߰���֮�ڽӵ����л���Ȩ���Ϊ-1(�ڽӾ���)
	*��num_V���ֲ���
	*/
	/*
	int V;
	int E;
	std::cout << "��������ͼ\n,�����붥�����ͻ���\n>";
	std::cin >> V >> E;
	Graph grap_no_direction(V,E);//��cin��������ͼ*/

	Graph grap_no_direction(set);//��������ͼ
	BinaryTree tree=nullptr;
	std::cout << "������ȱ����������������Ա�ʾ�������������\n";
	grap_no_direction.DFS_createBinaryTree(0, tree);//�Զ�������ʾ��DFS������

	grap_no_direction.refresh();
	std::cout << "������Ƚ����\n";
	grap_no_direction.DFS(visit, 0);//�����������

	
	grap_no_direction.refresh();
	std::cout << "\n��ȱ������\n";
	grap_no_direction.BFS(visit, 0);//�����������
	Graph_matrix*graph_matrix = grap_no_direction.New_get_matrix();//��ȡ����
	std::string path;
	std::cout << "����ִ�����ֲ���:\n";
	int op;
	while (std::cout << "�����·��:1\nɾ���� : 2\n�˳�:0\n"&&std::cin >> op)
	{
		if (op == 1)
		{
			std::cout << "���������������>";
			std::string first, second;
			std::cin >> first >> second;
			path=graph_matrix->closest_to(grap_no_direction._locate(first), grap_no_direction._locate(second));
			std::cout << path<<std::endl;
		}
		else if (op == 2)
		{
			std::cout << "����һ���������>";
			std::string V;
			std::cin >> V;
			grap_no_direction.del_V(grap_no_direction._locate(V));
		}
		else break;
	} 
		
	return 0;
}