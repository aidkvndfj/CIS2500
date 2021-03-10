#include "headerA3.h"

tweet* createTweet(tweet* tweetList) {
    tweet* tempTweet;
    tempTweet = malloc(sizeof(tweet));

    fgetc(stdin);
    printf("Enter a username: ");
    fgets(tempTweet->user, 51, stdin);
    strtok(tempTweet->user, "\n");
    printf("Enter the user's tweet: ");
    fgets(tempTweet->text, 141, stdin);
    strtok(tempTweet->text, "\n");
    tempTweet->id = 0;

    for (int i = 0; i < strlen(tempTweet->user); i++) {
        tempTweet->id += (int)tempTweet->user[i];
    }

    tempTweet->id += strlen(tempTweet->text);
    printf("Your computer-generated userid is %d.\n", tempTweet->id);

    // if (tweetList->next == NULL) {
    //     tweetList = tempTweet;
    // } else {
    //     while(tweetList->next != NULL) {
    //         tweetList = tweetList->next;
    //     }
    //     tweetList->next = tempTweet;
    // }

    return NULL;
}