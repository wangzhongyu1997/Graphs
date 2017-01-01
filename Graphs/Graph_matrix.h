#pragma once
#include<string>
typedef  std::string Data;

class Graph;
class Graph_matrix
{
public:
	friend class Graph;
	Graph_matrix(Graph_matrix&another);
	~Graph_matrix();

	std::string closest_to(int first, int destination);
	void dij_path(int index);

	void refesh();//���ü���S �Ա�   �ٴ�ʹ�õ޽�����˹�㷨
	void init();//��tableΪȫ���ɴ�
	void setValue(Graph*gp);
	int path[30];//ĳ���ڵ�ǰ�� ����dij_sort
	void add_E(int from,int des,int coast);
	void add_V(Data d);
	void del_E(int from, int des);
	void del_V(int index);

	
private:
	Graph_matrix(int n);
	int _n;//��ģ
	int table[30][30];//��//////////////////////*û���ö�̬���飬��Ϊ��ģ��֪�������ٴη���ռ�
	int distance[30];//���� dij_sort
	bool  S[30];//���� dij_sort
	Graph*relative;//��֮�������ͼ(�ڽӱ�)
};

