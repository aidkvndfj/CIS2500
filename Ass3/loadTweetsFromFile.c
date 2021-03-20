#include "headerA3.h"

void loadTweetsFromFile(tweet** tweetList) {
    FILE* inFile = NULL;
    tweet* newTweet;
    tweet* tempTweetList;
    char fileName[30];
    char tempWord[220];
    int currLetter;
    int i;

    currLetter = 0;
    tempTweetList = *tweetList;

    fflush(stdin);

    printf("Enter a filename to load from: ");
    scanf("%s", fileName);

    inFile = fopen(fileName, "r");

    if (inFile == NULL) {
        printf("ERROR: CANNOT READ FILE %s", fileName);
        return;
    }

    while (!feof(inFile)) {
        newTweet = malloc(sizeof(tweet));
        newTweet->next = NULL;
        currLetter = 1;

        fscanf(inFile, "%d", &newTweet->id);
        fgets(tempWord, 220, inFile);
        strtok(tempWord, "\n");
        strtok(tempWord, "\r");

        i = 0;
        while(tempWord[currLetter] != ',') {
            newTweet->user[i] = tempWord[currLetter];
            currLetter++;
            i++;
        }

        currLetter++;

        i = 0;
        while (tempWord[currLetter] != '\0') {
            newTweet->text[i] = tempWord[currLetter];
            currLetter++;
            i++;
        }

        if (tempWord[strlen(tempWord) - 2] == ',') {
            tempWord[strlen(tempWord) - 2] = '\0';
        }



        tempTweetList = *tweetList;
        if (tempTweetList == NULL) {
            *tweetList = newTweet;
        }
        else {
            while (tempTweetList->next != NULL) {
                tempTweetList = tempTweetList->next;
            }
            tempTweetList->next = newTweet;
        }
    }
}