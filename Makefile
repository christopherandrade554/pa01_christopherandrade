
CXX_FLAG = --std=c++11 -g

all: game

game: cards.o main.o utility.o
	g++ $(CXX_FLAG) -o game cards.o main.o utility.o


cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.o

clean:
	rm -f testrest testlist *.o