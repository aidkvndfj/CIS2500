#include "headerA3.h"

tweet* createTweet(tweet* tweetList) {
    // initialize tweets
    tweet* newTweet;
    tweet* tempTweet;
    tempTweet = tweetList;
    newTweet = malloc(sizeof(tweet));
    
    newTweet->next = NULL;
    newTweet->id = 0;

    // get username and tweet text
    fgetc(stdin);
    printf("Enter a username: ");
    fgets(newTweet->user, 51, stdin);
    newTweet->user[strlen(newTweet->user) - 1] = '\0';
    printf("Enter the user's tweet: ");
    fgets(newTweet->text, 141, stdin);
    newTweet->text[strlen(newTweet->text) - 1] = '\0';

    // get initial tweet id
    for (int i = 0; i < strlen(newTweet->user); i++) {
        newTweet->id += (int)newTweet->user[i];
    }

    newTweet->id += strlen(newTweet->text);

    //  backup checker
    if (tempTweet != NULL) {
        while(1) {
            if (newTweet->id == tempTweet->id) {
                newTweet->id += rand() % 1000;
                tempTweet = tweetList;
            } else if (tempTweet->next == NULL) {
                break;
            } else {
                tempTweet = tempTweet->next;
            }
        }
    }
    
    /*
    // checks to make sure the id is unique
    if (tempTweet != NULL) {
        // run at least once
        do {
            // if the new id is the same as the tweet we are curently looking at
            if (tempTweet->id == newTweet->id) {
                // add a random num from 0 to 999 ************************ FIX
                newTweet->id += rand() % 1000;
                // reset the list to make sure new id isn't already an id
                tempTweet = tweetList;
            } else { // if the current id isn't the same as the new id, move to next tweet
                tempTweet = tempTweet->next;
            }
        // while the next tweet isn't null(deosn't exsist)
        } while (tempTweet->next != NULL); 
    }
    */
    printf("Your computer-generated userid is %d.\n", newTweet->id);

    // add tweet to linkd list
    tempTweet = tweetList;
    if (tempTweet == NULL) {
        printf("UPDATED HEAD\n");
        tweetList = newTweet;
    } else {
        while(tempTweet->next != NULL) {
            tempTweet = tempTweet->next;
        }
        printf("ADDED POINTER\n");
        tempTweet->next = newTweet;
    }

    return tweetList;
}