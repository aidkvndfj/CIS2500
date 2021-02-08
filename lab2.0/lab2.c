#include "lab2.h"

int main() {
    char currChar;
    char *poemPtr = NULL;
    int wordsPerLine[10];
    int numberOfLines;
    int totalWords;
    int currPos;

    poemPtr = malloc(sizeof(char));

    for (int i = 0; i < 10; i++) {
        wordsPerLine[i] = 0;
    }

    numberOfLines = 0;
    totalWords = 0;
    currPos = 0;

    printf("Enter Poem\n");
    scanf("%c", &currChar);


    return 0;
}