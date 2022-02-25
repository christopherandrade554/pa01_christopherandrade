CXX_FLAG = --std=c++11 -g

all: game

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o

game: main.o cards.o
	g++ $(CXX_FLAG) -o game main.o cards.o

testcards.o: testcards.cpp
	g++ -c $(CXX_FLAG) testcards.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

clean:
	rm -f testcards main *.o