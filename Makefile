
install: main.o Searching.o
	g++ main.o Searching.o -o Searching

main.o: main.cpp
	g++ -c main.cpp

Searching.o: Searching.cpp Searching.h
	g++ -c Searching.cpp

clean:
	rm *.o Searching
