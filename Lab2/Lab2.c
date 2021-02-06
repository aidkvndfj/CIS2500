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
            realloc(wordsPerLine, sizeof(int) * (numLines + 1));
            wordsPerLine[numLines] = 0;
        }

        realloc(poemPtr, sizeof(char) * (currPos + 1));
        poemPtr[currPos] = currChar;

        currPos += 1;
        scanf("%c", &currChar);
    }

    for (int i = 0; i < numLines; i++) {
        printf("line %d: %d\n", i, wordsPerLine[i]);
    }

    printf("Lines: %d\nWords: %d\n", numLines, totalWords);
    printf("%s", poemPtr);

    /*
    char *currLine = NULL;
    int lineCount;
    int stringLen;

    lineCount = 0;
    currLine = malloc(sizeof(char) * MAX_STRING_LENGTH);
    fgets(&currLine, MAX_STRING_LENGTH, stdin);
    strtok(&currLine, "\n");

    while (strcmp(&currLine, ".") != 0) {
        stringLen = strlen(&currLine);
        currLine = realloc(currLine, sizeof(char) * stringLen + sizeof(char) * MAX_STRING_LENGTH);
        lineCount++;
        fgets(&currLine, MAX_STRING_LENGTH, stdin);
        printf("last: %s\n", &currLine);
    }

    for (int i = 0; i < lineCount; i++) {
        printf("%s\n", &currLine[i]);
    }
    */

    return 0;
}