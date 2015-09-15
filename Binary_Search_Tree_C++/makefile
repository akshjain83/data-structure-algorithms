CXX = g++
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS =

dictionary : dictionary.o bst.o main.o
	$(CXX) $(LDFLAGS) -o dictionary dictionary.o bst.o main.o

main.o : main.cpp dictionary.h
	$(CXX) $(CXXFLAGS) main.cpp

dictionary.o : dictionary.cpp dictionary.h bst.h
	$(CXX) $(CXXFLAGS) dictionary.cpp

bst.o : bst.cpp bst.h
	$(CXX) $(CXXFLAGS) bst.cpp

clean :
	rm -f core dictionary *.o

