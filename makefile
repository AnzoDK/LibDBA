CXX := g++
C := gcc
INCLUDES := -I./includes
CXX_FLAGS := -Wall -std=c++17
DEBUG := -g3
LINKER_OPTIONS := -lcurl -ljsoncpp
OBJECTS := main.o api.o
SRC := ./src

release: main.o
	$(CXX) $(CXX_FLAGS) $(INCLUDES) $(DEBUG) $(OBJECTS) -o dbaSearch $(LINKER_OPTIONS)
	make clean

main.o: api.o
	$(CXX) -c $(CXX_FLAGS) $(DEBUG) $(SRC)/main.cpp -o main.o $(LINKER_OPTIONS)

api.o:
	$(CXX) -c $(CXX_FLAGS) $(DEBUG) $(SRC)/api.cpp -o api.o $(LINKER_OPTIONS)

clean:
	-rm *.o