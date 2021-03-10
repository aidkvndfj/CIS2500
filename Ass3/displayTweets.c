#include "headerA3.h"

void displayTweets(tweet* tweetList) {
    tweet* tempTweet;
    tempTweet = tweetList;

    // If there is no tweets, print a error
    if (tempTweet == NULL) {
        printf("ERROR, NO TWEETS IN LIST\n");
    }
    else {
        // loop through the tweets printing and going to the next tweet
        while (tempTweet->next != NULL) {
            printf("%s:%s\nid:%d\n", tempTweet->user, tempTweet->text, tempTweet->id);
            tempTweet = tempTweet->next;
        }

        //print the final tweet
        printf("%s:%s\nid:%d\n", tempTweet->user, tempTweet->text, tempTweet->id);
    }
}