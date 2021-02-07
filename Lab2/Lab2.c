#include "Lab2.h"

int main(void) {
    char currChar;
    char *poemPtr = NULL;
    int *wordsPerLine = NULL;
    int numLines;
    int totalWords;
    int currPos;

    printf("Enter Poem\n");
    poemPtr = malloc(sizeof(char));
    wordsPerLine = malloc(sizeof(int));
    wordsPerLine[0] = 0;

    currPos = 0;
    totalWords = 0;
    numLines = 0;

    scanf("%c", &currChar);
    while (currChar != '.') {
        if (currChar == ' ') {
            totalWords += 1;
            wordsPerLine[numLines] += 1;
        }
        else if (currChar == '\n') {
            totalWords += 1;
            wordsPerLine[numLines] += 1;
            numLines += 1;
            wordsPerLine = realloc(wordsPerLine, sizeof(int) * (numLines + 1));
            wordsPerLine[numLines] = 0;
        }
        if (currChar != '\0') {
            poemPtr = realloc(poemPtr, sizeof(char) * (currPos + 1));
            poemPtr[currPos] = currChar;

            currPos += 1;
        }

        // printf("%d\n", currPos);
        scanf("%c", &currChar);
    }

    printf("%d words on %d lines\n", totalWords, numLines);

    for (int i = 0; i < numLines; i++) {
        printf("%d ", wordsPerLine[i]);
    }

    // printf("%s", poemPtr);

    return 0;
}