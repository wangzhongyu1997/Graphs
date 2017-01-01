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
	*���ò�˵��д�ĺ���

	Graph_matrix:
	string closest_to(int first, int destination);
	dij_path(int index);

	refesh();//���ü���S���Ա�   �ٴ�ʹ�õ޽�����˹�㷨
	init();//��tableΪȫ���ɴ�
	setValue(Graph*gp);

	add_E(int from,int des,int coast);**************************
	add_V(Data d);**���ĸ����������������໥�����������ȼ�*
	del_E(int from, int des);***********************************
	del_V(int index);******************************************

	Graph��
	DFS(void visit(Vnode&),int v);
	DFS_createBinaryTree( int v, BinaryNode* &T);
	BFS(void visit(Vnode&),int v);
	BFS2(void visit(Vnode&), int v);
	refresh();//Ϊ������ʰ��̯�ӣ��Ա���һ������

	add_V(Data d);*******************************************
	add_E(int from,int des,int coast);*************************
	del_E(int from,int des);***********************************
	del_V(int index);*****************************************
	*���⣬��ɾ��һ����ʱ����������������䣬�˵㱻���Ϊɾ������ɾ����֮�ڽӵ����л����ڽӱ�//���߰���֮�ڽӵ����л���Ȩ���Ϊ-1(�ڽӾ���)
	*��num_V���ֲ���
	*/
	int V = 6;
	int E = 8;
	


	//Graph gg(6, 8);//��cin����ͼ
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
	Graph_matrix*graph_with_matrix = grap_no_direction.New_get_matrix();//��ȡ����
	std::string path;
	
	path= graph_with_matrix->closest_to(0, 5);//��ȡ��
	std::cout << path<<std::endl;
	grap_no_direction.del_V(grap_no_direction._locate("V4"));
	path = graph_with_matrix->closest_to(0, 5);
	std::cout << path;
	delete graph_with_matrix;
	
	return 0;
}