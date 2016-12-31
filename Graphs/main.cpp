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
	*注意，在这个程序的逻辑里，邻接矩阵是服务于邻接表的。 eeeeeeeeeee
	*因为两个存储方式不同，我把他们封在不同的类里，并用指针聚合。快快快看看
	*另外，在删除一个点时，其他点的索引不变，此点被标记为删除，并删除与之邻接的所有弧（邻接表）//或者把与之邻接的所有弧的权标记为-1(邻接矩阵)
	*且num_V保持不变
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
	Graph_matrix*graph = gg.New_get_matrix();//获取矩阵
	std::string path;
	
	path=graph->closest_to(0, 5);
	std::cout << path<<std::endl;
	gg.del_V(gg._locate("V4"));
	path = graph->closest_to(0, 5);
	std::cout << path;
	delete graph;
	
	return 0;
}