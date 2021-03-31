COMPILE_FLAGS = -Wall -std=c99
O_FILES = main.o helperFunctions.o

tweetManager: ${O_FILES}
	gcc ${COMPILE_FLAGS} ${O_FILES} -o tweetManager

main.o: main.c headerA4.h
	gcc ${COMPILE_FLAGS} -c main.c

helperFunctions.o: helperFunctions.c helper.h
	gcc ${COMPILE_FLAGS} -c helperFunctions.c

clean:
	rm ${O_FILES} tweetManager