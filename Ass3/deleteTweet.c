#include "headerA3.h"

void deleteTweet(tweet** tweetList) {
    int numTweets;
    int tweetToDelete;
    int i;
    tweet *tempTweetList;

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

    tempTweetList = *tweetList;
    printf("Currently there are %d tweets.\n\n", numTweets);
    printf("Which tweet do you wish to delete - enter a vlue between 1 and %d:", numTweets);
    scanf("%d", &tweetToDelete);
    tweetToDelete -= 1;
    for (i = 0; i < tweetToDelete - 1; i++) {
        tempTweetList = tempTweetList->next;
    }
    printf("Tweet %d deleted. There are now %d tweets left\n", tempTweetList->next->id, numTweets - 1);
    tempTweetList->next = tempTweetList->next->next;

    // *tweetList = tempTweetList;
}