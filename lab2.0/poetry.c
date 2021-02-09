#include "header.h"

int main() {
    char currChar;
    char *poemPtr = NULL;
    int *wordsPerLine = NULL;
    int numberOfLines;
    int totalWords;
    int currPos;
    int i;

    wordsPerLine = malloc(sizeof(int));
    wordsPerLine[0] = 0;

    numberOfLines = 0;
    totalWords = 0;
    currPos = 0;

    printf("Enter Poem\n");
    scanf("%c", &currChar);

    while (currChar != '.') {
        if (currChar == ' ') {
            totalWords += 1;
            wordsPerLine[numberOfLines] += 1;
        }
        if (currChar == '\n') {
            totalWords += 1;
            wordsPerLine[numberOfLines] += 1;
            numberOfLines += 1;
            wordsPerLine = realloc(wordsPerLine, sizeof(int) * (numberOfLines + 1));
            wordsPerLine[numberOfLines] = 0;
        }

        if (currPos == 0) {
            poemPtr = malloc(sizeof(char));
        }
        else {
            poemPtr = realloc(poemPtr, sizeof(char) * (currPos + 1));
        }

        poemPtr[currPos] = currChar;
        currPos += 1;

        scanf("%c", &currChar);
    }

    poemPtr = realloc(poemPtr, sizeof(char) * (currPos + 1));
    poemPtr[currPos] = '\0';

    if (totalWords > 1) {
        printf("%d words on ", totalWords);
    }
    else {
        printf("%d word on ", totalWords);
    }

    if (numberOfLines > 1) {
        printf("%d lines\n", numberOfLines);
    }
    else {
        printf("%d line\n", numberOfLines);
    }

    for (i = 0; i < numberOfLines; i++) {
        printf("%d ", wordsPerLine[i]);
    }

    printf("\n");

    free(poemPtr);
    free(wordsPerLine);

    return 0;
}