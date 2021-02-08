#include "lab2.h"

int main() {
    char currChar;
    char *poemPtr = NULL;
    int wordsPerLine[10];
    int numberOfLines;
    int totalWords;
    int currPos;

    for (int i = 0; i < 10; i++) {
        wordsPerLine[i] = 0;
    }

    numberOfLines = 0;
    totalWords = 0;
    currPos = 0;

    printf("Enter Poem\n");
    scanf("%c", &currChar);

    while(currChar != '.') {
        if (currChar == ' ') {
            totalWords += 1;
            wordsPerLine[numberOfLines] += 1;
        }
        if (currChar == '\n') {
            totalWords += 1;
            wordsPerLine[numberOfLines] += 1;
            numberOfLines += 1;
        }

        if (currPos == 0) {
            poemPtr = malloc(sizeof(char));
        }
        else {
            printf("Curr Pos: %d, REALLOC\n", currPos);
            poemPtr = realloc(poemPtr, sizeof(char) * (currPos + 1));
        }

        poemPtr[currPos] = currChar;
        currPos += 1;


        scanf("%c", &currChar);
    }

    poemPtr = realloc(poemPtr, sizeof(char) * (currPos + 1));
    poemPtr[currPos] = '\0';

    printf("There are %d words on %d line\n", totalWords, numberOfLines);

    for (int i = 0; i < 10; i++) {
        printf("%d ", wordsPerLine[i]);
    }

    printf("%s", poemPtr);

    return 0;
}