#include "headerA3.h"

void loadTweetsFromFile(tweet** tweetList) {
    FILE* inFile = NULL;
    char fileName[30];
    int currLetter;
    tweet* newTweet;

    char tempWord[220];
    currLetter = 0;

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
        currLetter = 0;

        fscanf(inFile, "%d", &newTweet->id);
        fgets(tempWord, 220, inFile);
        strtok(tempWord, "\n");

        printf("%s\n", tempWord);
    }

}