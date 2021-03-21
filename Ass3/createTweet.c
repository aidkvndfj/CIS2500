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

    // check id and make sure no other tweets have it
    if (tempTweet != NULL) {
        // loop until break;
        while (1) {
            // if the id is the same as another tweets, add some random number to it and go back to begining of list
            if (newTweet->id == tempTweet->id) {
                newTweet->id += (1 + rand() * (999 - 1) / RAND_MAX);
                tempTweet = tweetList;
            // if next tweet doesn't exist, break
            }
            else if (tempTweet->next == NULL) {
                break;
            // move to next tweet
            }
            else {
                tempTweet = tempTweet->next;
            }
        }
    }
    printf("Your computer-generated userid is %d.\n", newTweet->id);

    free(newTweet);
    free(tempTweet);

    return newTweet;
}