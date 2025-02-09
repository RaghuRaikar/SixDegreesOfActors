CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = sixdegrees.o graphs.o
sixdegrees: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ sixdegrees.o graphs.o

graphs.o: graphs.cpp graphs.h
	$(CXX) -g $(CXXFLAGS) -c graphs.cpp

sixdegrees.o: graphs.cpp sixdegrees.cpp
	$(CXX) -g $(CXXFLAGS) -c sixdegrees.cpp

clean:
	rm *.o
	rm sixdegrees