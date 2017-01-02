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
	*注意，在这个程序的逻辑里，邻接矩阵是服务于邻接表的。 
	*因为两个存储方式不同，我把他们封在不同的类里，并用指针聚合。

	*邻接矩阵不保存Data
	*不得不说，写的很乱，我必须写很多注释来理清关系

	Graph_matrix:
	
	dij_path(int index);//缔结克拉斯算法

	refesh();//设置集合S，以便   再次使用缔结特拉斯算法
	init();//置table为全不可达
	setValue(Graph*gp);

	string closest_to(int first, int destination);*****************
	add_E(int from,int des,int coast);**************************
	add_V(Data d);**这五个函数在两个类中相互连锁，几乎等价*
	del_E(int from, int des);***********************************
	del_V(int index);******************************************

	Graph：
	DFS(void visit(Vnode&),int v);
	DFS_createBinaryTree( int v, BinaryNode* &T);
	BFS(void visit(Vnode&),int v);
	BFS2(void visit(Vnode&), int v);
	refresh();//为搜索收拾烂摊子，以便下一次搜索
	
	std::string closest_to(int first, int destination);************
	add_V(Data d);*******************************************
	add_E(int from,int des,int coast);*************************
	del_E(int from,int des);***********************************
	del_V(int index);*****************************************


	*另外，在删除一个点时，其他点的索引不变，此点被标记为删除，并删除与之邻接的所有弧（邻接表）//或者把与之邻接的所有弧的权标记为-1(邻接矩阵)
	*且num_V保持不变
	*/
	/*
	int V;
	int E;
	std::cout << "建立有向图\n,请输入顶点数和弧数\n>";
	std::cin >> V >> E;
	Graph grap_no_direction(V,E);//用cin建立有向图*/

	Graph grap_no_direction(set);//建立无向图
	BinaryTree tree=nullptr;
	std::cout << "深度优先遍历，建立二叉树以表示深度优先生成树\n";
	grap_no_direction.DFS_createBinaryTree(0, tree);//以二叉树表示的DFS生成树

	grap_no_direction.refresh();
	std::cout << "深度优先结果：\n";
	grap_no_direction.DFS(visit, 0);//深度优先搜索

	
	grap_no_direction.refresh();
	std::cout << "\n广度遍历结果\n";
	grap_no_direction.BFS(visit, 0);//广度优先搜索
	Graph_matrix*graph_matrix = grap_no_direction.New_get_matrix();//获取矩阵
	std::string path;
	std::cout << "下面执行两种操作:\n";
	int op;
	while (std::cout << "求最短路径:1\n删除点 : 2\n退出:0\n"&&std::cin >> op)
	{
		if (op == 1)
		{
			std::cout << "输入两个点的数据>";
			std::string first, second;
			std::cin >> first >> second;
			path=graph_matrix->closest_to(grap_no_direction._locate(first), grap_no_direction._locate(second));
			std::cout << path<<std::endl;
		}
		else if (op == 2)
		{
			std::cout << "输入一个点的数据>";
			std::string V;
			std::cin >> V;
			grap_no_direction.del_V(grap_no_direction._locate(V));
		}
		else break;
	} 
		
	return 0;
}