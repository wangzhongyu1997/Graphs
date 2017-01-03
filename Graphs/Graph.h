#pragma once
#include<string>
class Graph_matrix;//前置声明，将会用到Graph_matrix作为 New_get_matrix();的返回值
struct BinaryNode;
typedef std::string Data;
const int MAX_LENGHT = 100;

struct ArcNode
{
	int ToV;//所指向的节点的索引
	ArcNode* nearArc;//临近边
	int info;//信息
};

struct Vnode
{
	Data data;//节点唯一属性
	ArcNode *firstArc;
};
class Graph
{
public:
	friend class Graph_matrix;
	bool * visited;//标志数组

	void DFS(void visit(Vnode&),int v);
	void DFS(int v);//无用函数
	void DFS_createBinaryTree( int v, BinaryNode* &T);
	void BFS(void visit(Vnode&),int v);
	void BFS2(void visit(Vnode&), int v);
	std::string closest_to(int first, int destination);

	void refresh_visited();//为搜索收拾烂摊子
	void add_V(Data d);
	void add_E(int from,int des,int coast);
	bool del_E(int from,int des);
	void del_V(int index);
	Graph(void input(Data&Element));//无向图构造，只是为了体验一下函数作参
	Graph(int V, int E);//有向图构造
	~Graph();

	Graph_matrix* New_get_matrix();//请特别注意，返回的是一个动态的对象指针！！/只为避免复制
	int  _locate(const Data& e);
	
private:
	
	Vnode list[MAX_LENGHT];//节点表
	int num_V;//节点数
	int num_E;//边数
	Graph_matrix*relative;//与之关联的邻接矩阵
	bool right;//生成树往右转？
};

