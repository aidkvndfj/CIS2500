#include "headerA3.h"

void deleteTweet(tweet** tweetList) {
    int numTweets;
    int tweetToDelete;
    int i;
    tweet *tempTweetList;
    tweet *tweetToDeletePtr;

    tempTweetList = *tweetList;    
    numTweets = 0;
    tweetToDelete = 0;

    if (tempTweetList != NULL) {
        while (1) {
            numTweets++;
            if (tempTweetList->next == NULL) {
                break;
            } else {
                tempTweetList = tempTweetList->next;
            }
        }
    }

    if (numTweets == 0) {
        printf("Error, there are no tweets to delete");
        return;
    }

    tempTweetList = *tweetList;
    printf("Currently there are %d tweets.\n", numTweets);
    printf("Which tweet do you wish to delete - enter a vlue between 1 and %d:", numTweets);
    scanf("%d", &tweetToDelete);
    if (tweetToDelete == 1) {
        printf("Tweet %d deleted. ", tempTweetList->id);
        tweetToDeletePtr = *tweetList;
        *tweetList = tempTweetList->next;
        numTweets -= 1;
    }
    else {
        tweetToDelete -= 1;
        for (i = 0; i < tweetToDelete - 1; i++) {
            tempTweetList = tempTweetList->next;
        }

        printf("Tweet %d deleted. ", tempTweetList->next->id);
        tweetToDeletePtr = tempTweetList->next;
        tempTweetList->next = tempTweetList->next->next;
        numTweets -= 1;
    }

    if (numTweets == 0) {
        printf("There are no tweets remaining\n");
    } else {
        printf("There are %d tweets remaining", numTweets);
    }

    free(tweetToDeletePtr);

    // *tweetList = tempTweetList;
}