#pragma once
#include<string>
class Graph_matrix;//ǰ�������������õ�Graph_matrix��Ϊ New_get_matrix();�ķ���ֵ
struct BinaryNode;
typedef std::string Data;
const int MAX_LENGHT = 100;

struct ArcNode
{
	int ToV;//ָ��Ľڵ������
	ArcNode* nearArc;//�ٽ���
	int info;//��Ϣ
};

struct Vnode
{
	Data data;//�ڵ�Ψһ����
	ArcNode *firstArc;
};
class Graph
{
public:
	friend class Graph_matrix;
	bool * visited;//��־����

	void DFS(void visit(Vnode&),int v);
	void DFS(int v);//���ú���
	void DFS_createBinaryTree( int v, BinaryNode* &T);
	void BFS(void visit(Vnode&),int v);
	void BFS2(void visit(Vnode&), int v);
	std::string closest_to(int first, int destination);

	void refresh();//Ϊ������ʰ��̯��
	void add_V(Data d);
	void add_E(int from,int des,int coast);
	bool del_E(int from,int des);
	void del_V(int index);
	Graph(void input(Data&Element));//����ͼ���죬ֻ��Ϊ������һ�º�������
	Graph(int V, int E);//����ͼ����
	~Graph();

	Graph_matrix* New_get_matrix();//���ر�ע�⣬���ص���һ����̬�Ķ���ָ�룡��/ֻΪ���⸴��
	int  _locate(const Data& e);
	
private:
	
	Vnode list[MAX_LENGHT];//�ڵ��
	int num_V;//�ڵ���
	int num_E;//����
	Graph_matrix*relative;//��֮�������ڽӾ���
	bool right;//����������ת��
};

