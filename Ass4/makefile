COMPILE_FLAGS = -Wall -std=c99 -ggdb3
O_FILES = testA4.o helper.o queueFunctions.o miscFunctions.o

testA4: ${O_FILES}
	gcc ${COMPILE_FLAGS} ${O_FILES} -o testA4

testA4.o: testA4.c headerA4.h
	gcc ${COMPILE_FLAGS} -c testA4.c

helper.o: helper.c helper.h
	gcc ${COMPILE_FLAGS} -c helper.c

queueFunctions.o: queueFunctions.c headerA4.h
	gcc ${COMPILE_FLAGS} -c queueFunctions.c

miscFunctions.o: miscFunctions.c headerA4.h
	gcc ${COMPILE_FLAGS} -c miscFunctions.c

clean:
	rm ${O_FILES} testA4