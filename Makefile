EXENAME = final
OBJS =  main.o
CXX = clang++
CXXFLAGS = $(CS255) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm -lpthread

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

test: test.o catchmain.o graph.o BFS.o landmarkpath.o dijkstras.o
	$(LD) catchmain.o landmarkpath.o dijkstras.o graph.o BFS.o test.o   $(LDFLAGS) -o test

test.o : test.cpp BFS.h graph.cpp graph.h cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) test.cpp

graph.o : graph.cpp graph.h 
	$(CXX) $(CXXFLAGS) graph.cpp

BFS.o : BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

landmarkpath.o : landmarkpath.cpp landmarkpath.h
	$(CXX) $(CXXFLAGS) landmarkpath.cpp

dijkstras.o : dijkstras.cpp dijkstras.cpp
	$(CXX) $(CXXFLAGS) dijkstras.cpp

catchmain.o : cs225/catch/catch.hpp cs225/catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

main.o : BFS.h dijkstras.h graph.h edge.h landmarkpath.h main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

final: BFS.o graph.o main.o 
	$(LD) landmarkpath.o dijkstras.o graph.o BFS.o main.o $(LDFLAGS) -o $(EXENAME)

clean :
	-rm -f *.o $(EXENAME) test

    
.PHONY: output_msg


