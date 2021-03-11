#include "headerA3.h"
#include "helper.h"

void countStopWords(tweet* tweetList) {
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

    tempTweetList = tweetList;

    stopWordCounter = 0;
    tweetCounter = 0;
    currLetter = 0;

    if (tempTweetList != NULL) {
        while (1) {
            tweetCounter++;
            for (i = 0; i <= strlen(tempTweetList->text); i++) {
                if (!isEndWordChar(tempTweetList->text[i])) {
                    tempWord[currLetter] = tempTweetList->text[i];
                    currLetter++;
                } else {
                    for (j = 0; j < 25; j++) {
                        if (strcmp(tempWord, stopWords[j]) == 0) {
                            stopWordCounter++;
                            break;
                        }
                    }
                    for (j = 0; j < currLetter; j++) {
                        tempWord[j] = '\0';
                    }
                    currLetter = 0;
                }
            }
            

            if (tempTweetList->next == NULL) {
                break;
            }
            else {
                tempTweetList = tempTweetList->next;
            }
        }
    }

    printf("Across %d tweets, %d stop words were found.\n", tweetCounter, stopWordCounter);
}