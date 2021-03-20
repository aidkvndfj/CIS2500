#include "headerA3.h"

void deleteTweet(tweet** tweetList) {
    int numTweets;
    int tweetToDelete;
    int i;
    tweet *tempTweetList;
    tweet *tweetToDeletePtr;

    // set temp list to the tweet lsit
    tempTweetList = *tweetList;    
    numTweets = 0;
    tweetToDelete = 0;

    // loop through the tweets and count how many there are.
    if (tempTweetList != NULL) {
        // loop untill break
        while (1) {
            numTweets++;
            // if there not another tweet, break out, otherwise move on
            if (tempTweetList->next == NULL) {
                break;
            } else {
                tempTweetList = tempTweetList->next;
            }
        }
    }

    // if there are no tweets, exit func
    if (numTweets == 0) {
        printf("Error, there are no tweets to delete");
        return;
    }

    // get the tweet to delete
    tempTweetList = *tweetList;
    printf("Currently there are %d tweets.\n", numTweets);
    printf("Which tweet do you wish to delete - enter a vlue between 1 and %d:", numTweets);
    scanf("%d", &tweetToDelete);

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
        // loop untill we are at the tweet before the one to delete
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
    } else {
        printf("There are %d tweets remaining", numTweets);
    }

    // free deleted tweet
    free(tweetToDeletePtr);
}