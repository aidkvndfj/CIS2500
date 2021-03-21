#include "headerA3.h"

void loadTweetsFromFile(tweet** tweetList) {
    FILE* inFile = NULL;
    tweet* newTweet;
    char fileName[30];
    char tempWord[220];
    int currLetter;
    int i;

    currLetter = 0;

    // make sure stream in clear
    fflush(stdin);

    // get the filename
    printf("Enter a filename to load from: ");
    scanf("%s", fileName);

    // open file
    inFile = fopen(fileName, "r");

    // make sure there was no errors opening file
    if (inFile == NULL) {
        printf("ERROR: CANNOT READ FILE %s", fileName);
        return;
    }

    // go until end of file
    while (!feof(inFile)) {
        // make a new tweet and set it to null
        newTweet = malloc(sizeof(tweet));
        newTweet->next = NULL;
        currLetter = 1;

        // get the tweet id, and the rest of the text
        fscanf(inFile, "%d", &newTweet->id);
        fgets(tempWord, 220, inFile);
        strtok(tempWord, "\n");
        strtok(tempWord, "\r");

        // get the user name and write it to tweets user
        i = 0;
        while (tempWord[currLetter] != ',') {
            newTweet->user[i] = tempWord[currLetter];
            currLetter++;
            i++;
        }

        currLetter++;

        // get the tweet text and write it to the tweets text
        i = 0;
        while (tempWord[currLetter] != '\0') {
            newTweet->text[i] = tempWord[currLetter];
            currLetter++;
            i++;
        }

        addNodeToList(tweetList, newTweet);
    }

    free(newTweet);
    fclose(inFile);

    // say tweet import was a success.
    printf("Tweets imported!\n");
}