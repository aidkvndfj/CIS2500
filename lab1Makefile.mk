lab1_output: lab1.o lab1Main.o 
    gcc lab1.o lab1Main.o -o lab1_output 

lab1.o: lab1.c lab1.h
    gcc -Wall -std=c99 -c lab1.c 

lab1Mina.o: lab1Main.c lab1.h
    gcc -Wall -std=c99 -c lab1Main.c 

clean:
    rm *.o lab1_output