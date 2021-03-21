#include "headerA3.h"
#include "helper.h"

void countStopWords(tweet* tweetList) {
    // declare variables
    tweet* tempTweetList;
    int stopWordCounter;
    int tweetCounter;
    int i;
    int j;
    int currLetter;
    char tempWord[151];
    char stopWords[][5] = {
        "a",
        "an",
        "and",
        "are",
        "as",
        "at",
        "be",
        "by",
        "for",
        "from",
        "has",
        "he",
        "in",
        "is",
        "it",
        "its",
        "of",
        "on",
        "that",
        "the",
        "to",
        "was",
        "were",
        "will",
        "with"};

    // Initalize Variables
    tempTweetList = tweetList;

    stopWordCounter = 0;
    tweetCounter = 0;
    currLetter = 0;

    // make sure the tweet list isn't empty
    if (tempTweetList != NULL) {
        // repeat until a break
        while (1) {
            // keep track of number of tweets scaned
            tweetCounter++;
            // loop thorough current tweets text
            for (i = 0; i <= strlen(tempTweetList->text); i++) {
                // if the current word is not a end word char (space, comma, etc.)
                if (!isEndWordChar(tempTweetList->text[i])) {
                    // add the char to a temp word
                    tempWord[currLetter] = tolower(tempTweetList->text[i]);
                    currLetter++;
                } else {
                    // loop thorugh the stop words
                    for (j = 0; j < 25; j++) {
                        // if the current word is a stop word
                        if (strcmp(tempWord, stopWords[j]) == 0) {
                            // add 1 to the counter and end the loop
                            stopWordCounter++;
                            break;
                        }
                    }
                    // clear temp word
                    for (j = 0; j < currLetter; j++) {
                        tempWord[j] = '\0';
                    }
                    // set the current letter to 0
                    currLetter = 0;
                }
            }
            
            // if the next tweet is null(doesn't exsist), finish the loop
            if (tempTweetList->next == NULL) {
                break;
            } // move on to next tweet
            else {
                tempTweetList = tempTweetList->next;
            }
        }
    }

    // print the info.
    printf("Across %d tweets, %d stop words were found.\n", tweetCounter, stopWordCounter);
}