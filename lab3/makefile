lab3: main.o iterativeFibonacci.o iterativeSumNOdd.o recursiveFibonacci.o recursiveSumNOdd.o
	gcc -Wall -std=c99 main.o iterativeFibonacci.o iterativeSumNOdd.o recursiveFibonacci.o recursiveSumNOdd.o -o lab3
iterativeFibonacci.o: iterativeFibonacci.c lab3.h
	gcc -Wall -std=c99 -c iterativeFibonacci.c
iterativeSumNOdd.o: iterativeSumNOdd.c lab3.h
	gcc -Wall -std=c99 -c iterativeSumNOdd.c
recursiveFibonacci.o: recursiveFibonacci.c lab3.h
	gcc -Wall -std=c99 -c recursiveFibonacci.c
recursiveSumNOdd.o: recursiveSumNOdd.c lab3.h
	gcc -Wall -std=c99 -c recursiveSumNOdd.c
main.o: main.c lab3.h
	gcc -Wall -std=c99 -c main.c
clean:
	rm *.o lab3
