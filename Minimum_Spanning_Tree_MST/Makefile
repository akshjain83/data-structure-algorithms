CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

mst: MSTapp.o Graph.o MinPriority.o
	$(CXX) $(CXXFLAGS) -o mst MinPriority.o Graph.o MSTapp.o

MSTapp.o: MSTapp.cpp MSTapp.h Graph.h

Graph.o: Graph.cpp Graph.h MinPriority.h

Minpriority.o: MinPriority.cpp MinPriority.h

clean:
	rm -f *.o mst
