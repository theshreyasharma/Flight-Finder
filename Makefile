EXENAME = final
OBJS =  main.o

CXX = clang++
CXXFLAGS = $(CS255) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

all : $(EXENAME)

# $(EXENAME) : $(OBJS)
# 	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

test: test.o catchmain.o graph.o BFS.o
	$(LD) catchmain.o test.o $(LDFLAGS) -o test

test.o : test.cpp BFS.h graph.h cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) test.cpp

graph.o : graph.h 
	$(CXX) $(CXXFLAGS) graph.cpp

BFS.o : BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

catchmain.o : cs225/catch/catch.hpp cs225/catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

final: main.o graph.o
	$(LD) main.o $(LDFLAGS) -o $(EXENAME)

clean :
	-rm -f *.o $(EXENAME) test



# Be sure to add output_msg as dependency target for your `intro` binary

# test: output_msg tests.o PNG.o HSLAPixel.o lodepng.o intro.o
# 	$(LD) tests.o PNG.o HSLAPixel.o lodepng.o intro.o $(LDFLAGS) -o test

# tests.o: tests/tests.cpp tests/catch.hpp cs225/PNG.h cs225/HSLAPixel.h
# 	$(CXX) $(CXXFLAGS) tests/tests.cpp
    
.PHONY: output_msg


# # Executable names:
# EXE = final
# TEST = test

# # Add all object files needed for compiling:
# EXE_OBJ = main.o
# OBJS = graph.o main.o

# # Generated files
# # CLEAN_RM = images/Out.png
# bfs.txt, djikstra.txt, landmark.txt

# # Use the cs225 makefile template:
# include cs225/make/cs225.mk

# final: main.cpp
# 		clang++ -Wall -std=c++11 main.cpp -o final

# test: test.cpp graph.cpp BFS.cpp catch.hpp
# 		clang++ -Wall -std=c++11 test.cpp -o test