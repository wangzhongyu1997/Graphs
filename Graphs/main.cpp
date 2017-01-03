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
	*���⣬��ɾ��һ����ʱ����������������䣬�˵㱻���Ϊɾ������ɾ����֮�ڽӵ����л����ڽӱ�//���߰���֮�ڽӵ����л���Ȩ���Ϊ-1(�ڽӾ���)
	*��num_V���ֲ���
	*/
	int op0 = 0;
	while (std::cout<<"����1��������ͼ������2��������ͼ���������˳�\n>"&&std::cin>>op0)
	{
		if (op0 == 1)
		{
			std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-����ͼ�Ĳ���-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
			Graph grap_no_direction(set);//��������ͼ
			BinaryTree tree = nullptr;
			std::cout << "������ȱ����������������Ա�ʾ�������������\n";
			grap_no_direction.DFS_createBinaryTree(0, tree);//�Զ�������ʾ��DFS������

			grap_no_direction.refresh_visited();
			std::cout << "������Ƚ����\n";
			grap_no_direction.DFS(visit, 0);//�����������

			grap_no_direction.refresh_visited();
			std::cout << "\n��ȱ������\n";
			grap_no_direction.BFS(visit, 0);//�����������
			Graph_matrix*graph_matrix = grap_no_direction.New_get_matrix();//��ȡ����
			std::string path;
			std::cout << "\n\n����ִ�����ֲ���:\n\n";
			int op;
			while (std::cout << "\t�����·��:1\n\tɾ���� : 2\n\t������һ��:0\n>"&&std::cin >> op)
			{
				if (op == 1)
				{
					std::cout << "���������������>";
					std::string first, second;
					std::cin >> first >> second;
					path = graph_matrix->closest_to(grap_no_direction._locate(first), grap_no_direction._locate(second));
					std::cout << path << std::endl;
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
		}
		else if (op0 == 2)

		{
			std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-����ͼ�Ĳ���-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
			int V;
			int E;
			std::cout << "��������ͼ,�����붥�����ͻ���\n>";
			std::cin >> V >> E;
			Graph grap_with_direction(V, E);//��cin��������ͼ

			BinaryTree tree = nullptr;
			std::cout << "������ȱ����������������Ա�ʾ�������������\n";
			grap_with_direction.DFS_createBinaryTree(0, tree);//�Զ�������ʾ��DFS������

			grap_with_direction.refresh_visited();
			std::cout << "������Ƚ����\n";
			grap_with_direction.DFS(visit, 0);//�����������


			grap_with_direction.refresh_visited();
			std::cout << "\n��ȱ������\n";
			grap_with_direction.BFS(visit, 0);//�����������
			grap_with_direction.New_get_matrix();//���ɾ���
			std::string path;
			std::cout << "\n\n����ִ�����ֲ���:\n\n";
			int op;
			while (std::cout << "\t�����·��:1\n\tɾ���� : 2\n\t������һ��:0\n>"&&std::cin >> op)
			{
				if (op == 1)
				{
					std::cout << "���������������>";
					std::string first, second;
					std::cin >> first >> second;
					path = grap_with_direction.closest_to(grap_with_direction._locate(first), grap_with_direction._locate(second));
					std::cout << path << std::endl;
				}
				else if (op == 2)
				{
					std::cout << "����һ���������>";
					std::string V;
					std::cin >> V;
					grap_with_direction.del_V(grap_with_direction._locate(V));
				}
				else break;
			}
		}
		else
			break;//��������
	}
	return 0;
}