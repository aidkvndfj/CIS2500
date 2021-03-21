#include "headerA3.h"

// linked list function - required after you create a tweet or load tweets from a file
void addNodeToList(tweet** tweetList, tweet* node) {
    tweet* tempTweetList;

    // add tweet to list
    tempTweetList = *tweetList;
    // if the tweet list is empty, make it first tweet
    if (*tweetList == NULL) {
        *tweetList = node;
    }
    // otherwise loop to end of list, and append new tweet
    else {
        while (tempTweetList->next != NULL) {
            tempTweetList = tempTweetList->next;
        }
        tempTweetList->next = node;
    }

    free(tempTweetList);
}