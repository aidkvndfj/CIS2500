fleschIndex: fleschIndex.o main.o
	gcc -Wall -std=c99 fleschIndex.o main.o -o fleschIndex
fleschIndex.o: fleschIndex.c fleschIndex.h
	gcc -Wall -std=c99 -c fleschIndex.c
main.o: main.c fleschIndex.h
	gcc -Wall -std=c99 -c main.c99
clean:
	rm *.o fleschIndex