gg=g++ -std=c++11 
objects=CircleList_Queue.o  Graph.o  Graph_matrix.o  Mqueue.o  main.o  
graphhhh.exe:$(objects)
	$(gg) -o graphhhh.exe  $(objects) 
CircleList_Queue.o:CircleList_Queue.cpp  CircleList_Queue.h 
	$(gg)  -c CircleList_Queue.cpp 
Graph.o:Graph.cpp  Graph.h 
	$(gg)  -c Graph.cpp 
Graph_matrix.o:Graph_matrix.cpp  Graph_matrix.h 
	$(gg)  -c Graph_matrix.cpp 
Mqueue.o:Mqueue.cpp  Mqueue.h 
	$(gg)  -c Mqueue.cpp 
main.o:main.cpp  CircleList_Queue.h  Graph.h  Graph_matrix.h  Mqueue.h  
	$(gg)  -c main.cpp 
.PHONY : clean 

clean:
	del  $(objects)