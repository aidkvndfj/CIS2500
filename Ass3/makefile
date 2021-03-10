COMPILE_FLAGS = -Wall -std=c99
O_FILES = main.o helperFunctions.o addNodeToList.o countStopWords.o createTweet.o deleteTweet.o displayTweets.o loadTweetsFromFile.o saveTweetsToFile.o searchTweetsByKeyWord.o

tweetManager: ${O_FILES}
	gcc ${COMPILE_FLAGS} ${O_FILES} -o tweetManager

main.o: main.c headerA3.h
	gcc ${COMPILE_FLAGS} -c main.c

helperFunctions.o: helperFunctions.c headerA3.h
	gcc ${COMPILE_FLAGS} -c helperFunctions.c

addNodeToList.o: addNodeToList.c headerA3.h
	gcc ${COMPILE_FLAGS} -c addNodeToList.c

countStopWords.o: countStopWords.c headerA3.h
	gcc ${COMPILE_FLAGS} -c countStopWords.c

createTweet.o: createTweet.c headerA3.h
	gcc ${COMPILE_FLAGS} -c createTweet.c

deleteTweet.o: deleteTweet.c headerA3.h
	gcc ${COMPILE_FLAGS} -c deleteTweet.c 

displayTweets.o: displayTweets.c headerA3.h
	gcc ${COMPILE_FLAGS} -c displayTweets.c

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h
	gcc ${COMPILE_FLAGS} -c loadTweetsFromFile.c

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h
	gcc ${COMPILE_FLAGS} -c saveTweetsToFile.c

searchTweetsByKeyWord.o: searchTweetsByKeyWord.c headerA3.h
	gcc ${COMPILE_FLAGS} -c searchTweetsByKeyWord.c

clean:
	rm ${O_FILES} tweetManager