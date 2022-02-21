CXX_FLAG = --std=c++11 -g

all: game

game: main.o 
	g++ $(CXX_FLAG) -o game main.o 

util: utility.o
	g++ $(CXX_FLAG) -o util utility.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp


utility.o: utility.cpp 
	g++ -c $(CXX_FLAG) utility.cpp
	

clean:
	rm -f main *.o

 

