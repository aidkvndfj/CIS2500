#include "headerA3.h"

void saveTweetsToFile(tweet* tweetList) {
    FILE *outFile = NULL;
    tweet *tempTweetList;
    char fileName[40];

    tempTweetList = tweetList;

    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);

    outFile = fopen(fileName, "w");

    if (tempTweetList != NULL) {
        while (1) {
            // fprintf(outFile, "%d,%s,%c%s%c", tempTweetList->id, tempTweetList->user, '"', tempTweetList->text, '"');
            fprintf(outFile, "%d,%s,%s\n", tempTweetList->id, tempTweetList->user, tempTweetList->text);

            if (tempTweetList->next == NULL) {
                break;
            } else {
                tempTweetList = tempTweetList->next;
            }
        }
    }

    fclose(outFile);
}