#include "headerA3.h"

void deleteTweet(tweet **tweetList) {
    int numTweets;
    int tweetToDelete;
    int i;
    tweet *tempTweetList;
    tweet *tweetToDeletePtr;

    // set temp list to the tweet list
    tempTweetList = *tweetList;
    numTweets = 0;
    tweetToDelete = 0;

    // if there are no tweets, exit func
    if (*tweetList == NULL) {
        printf("ERROR: there are no tweets to delete\n");
        return;
    }

    // loop through the tweets and count how many there are.
    if (tempTweetList != NULL) {
        // loop until break
        while (1) {
            numTweets++;
            // if there not another tweet, break out, otherwise move on
            if (tempTweetList->next == NULL) {
                break;
            }
            else {
                tempTweetList = tempTweetList->next;
            }
        }
    }

    // get the tweet to delete
    tempTweetList = *tweetList;
    printf("Currently there are %d tweets.\n", numTweets);
    printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", numTweets);
    scanf("%d", &tweetToDelete);

    // make sure tweet is within range
    while (tweetToDelete < 1 || tweetToDelete > numTweets) {
        printf("ERROR: number \"%d\" is not within the range.\n", tweetToDelete);
        printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", numTweets);
        scanf("%d", &tweetToDelete);
    }

    // if they want to delete the first tweets
    if (tweetToDelete == 1) {
        printf("Tweet %d deleted. ", tempTweetList->id);
        // set delete ptr in order to free later
        tweetToDeletePtr = *tweetList;
        // set the main tweet list to the next tweet
        *tweetList = tempTweetList->next;
        // subtract number of tweets by 1
        numTweets -= 1;
    }
    else {
        // remove 1 from tweettodelete so we are looking at correct index
        tweetToDelete -= 1;
        // loop until we are at the tweet before the one to delete
        for (i = 0; i < tweetToDelete - 1; i++) {
            tempTweetList = tempTweetList->next;
        }

        printf("Tweet %d deleted. ", tempTweetList->next->id);
        // set delete prt in order to free later
        tweetToDeletePtr = tempTweetList->next;
        // set the next tweet to next next tweet removing the tweet we want to delete from the list
        tempTweetList->next = tempTweetList->next->next;
        // subtract 1 from number of tweets
        numTweets -= 1;
    }

    // if there are 0 tweets, say so, otherwise print tweets rmaining
    if (numTweets == 0) {
        printf("There are no tweets remaining\n");
    }
    else if (numTweets == 1) {
        printf("There is %d tweet remaining\n", numTweets);
    }
    else {
        printf("There are %d tweets remaining\n", numTweets);
    }

    // free deleted tweet
    free(tweetToDeletePtr);
    free(tempTweetList);
}