
all: tests game

tests: tests.o cards.o utility.o
	g++ -Wall -Wno-uninitialized $(LDFLAGS) $^ -o $@

game: main.o cards.o utility.o
	g++ -Wall -Wno-uninitialized $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f tests game *.o
