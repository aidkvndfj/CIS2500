#include "helper.h"

void sortID(tweet** head, tweet** tail) {
    int swapped;
    tweet *tempHead;
    tweet *lastTweet;

    lastTweet = NULL;

    // if the queue is empty, exit.
    if (isEmpty(*head)) {
        printf("Nothing to sort\n");
        return;
    }

    // go through the queue until all tweets have been checked at least once that they are in the right order.
    do {
        // set swapped to 0 and the temp head to actual head.
        swapped = 0;    
        tempHead = *head;
        // while the next tweet isn't the last tweet sorted tweet.
        while (tempHead->next != lastTweet) {
            // if the current id is greater then the next id, swap tweets.
            if (tempHead->id > tempHead->next->id) {
                SwapTweets(tempHead, tempHead->next);
                swapped = 1;
            }
            // move to next tweet
            tempHead = tempHead->next;
        }
        // set the last sorted tweet to the current tweet/temp head.
        lastTweet = tempHead;
    } while(swapped);
}

void reverse(tweet** head, tweet** tail) {
    int swapped;
    tweet* tempHead;
    tweet* lastTweet;

    lastTweet = NULL;

    // if the queue is empty, exit.
    if (isEmpty(*head)) {
        printf("Nothing to reverse\n");
        return;
    }

    // go through the queue swapping each element
    do {
        // set swapped to 0 and the temp head to actual head.
        swapped = 0;
        tempHead = *head;
        // while the next tweet isn't the last tweet reversed tweet.
        while (tempHead->next != lastTweet) {
            // swap the tweets.
            SwapTweets(tempHead, tempHead->next);
            swapped = 1;
            // move to next tweet
            tempHead = tempHead->next;
        }
        // set the last reversed tweet to the current tweet/temp head.
        lastTweet = tempHead;
    } while (swapped);
}

void sortUsername(tweet** head, tweet** tail) {
    int swapped;
    tweet* tempHead;
    tweet* lastTweet;

    lastTweet = NULL;

    // if the queue is empty, exit.
    if (isEmpty(*head)) {
        printf("Nothing to sort\n");
        return;
    }

    // go through the queue until all tweets have been checked at least once that they are in the right order.
    do {
        // set swapped to 0 and the temp head to actual head.
        swapped = 0;
        tempHead = *head;
        // while the next tweet isn't the last tweet sorted tweet.
        while (tempHead->next != lastTweet) {
            // if the current username is greater then the last username, swap.
            if (strcmp(tempHead->user, tempHead->next->user) > 0) {
                SwapTweets(tempHead, tempHead->next);
                swapped = 1;
            }
            // move to next tweet
            tempHead = tempHead->next;
        }
        // set the last sorted tweet to the current tweet/temp head.
        lastTweet = tempHead;
    } while (swapped);
}
