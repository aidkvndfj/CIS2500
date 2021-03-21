#include "headerA3.h"

void saveTweetsToFile(tweet *tweetList) {
    FILE *outFile = NULL;
    tweet *tempTweetList;
    char fileName[40];

    tempTweetList = tweetList;

    // make sure tweet list is not empty
    if (tweetList == NULL) {
        printf("ERROR: There are no tweets to save!\n");
        return;
    }

    // get the filename
    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);

    outFile = fopen(fileName, "w");

    // loop until break
    while (1) {
        // print the current tweets information
        fprintf(outFile, "%d,%s,%s\n", tempTweetList->id, tempTweetList->user, tempTweetList->text);

        // if there is no next tweet, break, otherwise move on to next tweet
        if (tempTweetList->next == NULL) {
            break;
        }
        else {
            tempTweetList = tempTweetList->next;
        }
    }

    // close file
    fclose(outFile);
    free(tempTweetList);
}