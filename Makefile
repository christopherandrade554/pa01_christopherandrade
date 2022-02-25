CXX = g++


CXXFLAGS = -Wall -Wno-uninitialized

BINARIES= tests game

COMMON_OBJECT_FILES = cards.o utility.o

all: tests game

tests: tests.o cards.o utility.o
	g++ -Wall -Wno-uninitialized $(LDFLAGS) $^ -o $@

game: main.o cards.o utility.o
	g++ -Wall -Wno-uninitialized $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f tests game *.o