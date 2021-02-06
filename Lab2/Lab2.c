#include "Lab2.h"

int main(void) {
    char currChar;
    char *lineArray = NULL;
    int numLines;
    int totalWords;
    int currPos;

    printf("Enter Poem\n");
    lineArray = malloc(sizeof(char));

    currPos = 0;
    totalWords = 0;
    numLines = 0;

    scanf("%c", &currChar);
    while (currChar != '.') {
        if (currChar == ' ') {
            totalWords += 1;
        }
        else if (currChar == '\n') {
            numLines += 1;
            totalWords += 1;
        }
        realloc(lineArray, sizeof(char) * (currPos + 1));
        lineArray[currPos] = currChar;

        currPos += 1;
        scanf("%c", &currChar);
    }

    printf("Lines: %d\nWords: %d\n", numLines, totalWords);
    printf("%s", lineArray);

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