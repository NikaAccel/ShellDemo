CXX = g++
CXXFLAGS = -Wall -ggdb

MAIN = test
OBJ = $(MAIN).o HStack.o

$(MAIN).exe: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(MAIN).exe

$(MAIN).o: $(MAIN).cpp HStack.hpp
HStack.o: HStack.cpp HStack.hpp

run: $(MAIN).exe
	./$(MAIN).exe

clean:
	rm -f *.o *.exe

all: $(MAIN).exe




