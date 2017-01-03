gg=g++ -std=c++11 
objects=BinaryTree.o  CircleList_Queue.o  Graph.o  Graph_matrix.o  main.o  
Graph.exe:$(objects)
	$(gg) -o Graph.exe  $(objects) 
BinaryTree.o:BinaryTree.cpp  BinaryTree.h 
	$(gg)  -c BinaryTree.cpp 
CircleList_Queue.o:CircleList_Queue.cpp  CircleList_Queue.h 
	$(gg)  -c CircleList_Queue.cpp 
Graph.o:Graph.cpp  Graph.h 
	$(gg)  -c Graph.cpp 
Graph_matrix.o:Graph_matrix.cpp  Graph_matrix.h 
	$(gg)  -c Graph_matrix.cpp 
main.o:main.cpp  BinaryTree.h  CircleList_Queue.h  Graph.h  Graph_matrix.h  
	$(gg)  -c main.cpp 
.PHONY : clean 

clean:
	del  $(objects)