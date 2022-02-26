CXX_FLAG = --std=c++11 -g

all: game

game: cards.o utility.o main.o
	g++ $(CXX_FLAG) -o game cards.o utility.o main.o

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

clean:
	rm -f utility cards main *.o