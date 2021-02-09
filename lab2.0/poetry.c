#include "header.h"

int main() {
    char currChar;
    char *poemPtr = NULL;
    int *wordsPerLine = NULL;
    int charsInCurrWord;
    int charsInLine;
    int numberOfLines;
    int totalWords;
    int currPos;
    int i;

    // initalize variables
    wordsPerLine = malloc(sizeof(int));
    wordsPerLine[0] = 0;

    numberOfLines = 0;
    totalWords = 0;
    currPos = 0;

    charsInCurrWord = 0;
    charsInLine = 0;

    // get the first char
    printf("Enter Poem\n");
    scanf("%c", &currChar);

    while (currChar != '.') {
        // if the current char is a space
        if (currChar == ' ') {
            // add 1 to total words
            totalWords += 1;
            // add 1 to the words of the current line
            wordsPerLine[numberOfLines] += 1;

            //reset the chars in the current word
            charsInCurrWord = 0;
        }
        // if the current char is a newline
        if (currChar == '\n') {
            // add 1 to the total words
            totalWords += 1;
            // add 1 to the words of the current line
            wordsPerLine[numberOfLines] += 1;
            // add 1 to the number of lines
            numberOfLines += 1;
            // realloc the words per line to allow another line
            wordsPerLine = realloc(wordsPerLine, sizeof(int) * (numberOfLines + 1));
            // set the words of the new current line to 0
            wordsPerLine[numberOfLines] = 0;

            // reset the chars in the curr word and the line
            charsInCurrWord = 0;
            charsInLine = 0;
        }

        // if the current position is 0 then malloc, otherwise realloc
        if (currPos == 0) {
            poemPtr = malloc(sizeof(char));
        }
        else {
            poemPtr = realloc(poemPtr, sizeof(char) * (currPos + 1));
        }

        // if the current char isn't a newline space or terminating add 1 to chars in curr words, if it isnt a newline or terminating add 1 to chars in line
        if (currChar != '\n' && currChar != ' ' && currChar != '\0') {
            charsInCurrWord +=1;
        } else if (currChar != '\n' && currChar != '\0') {
            charsInLine += 1;
        }

        // set the char at the current pos in the poemPtr array to the curr char then add 1 to current pos
        poemPtr[currPos] = currChar;
        currPos += 1;
        
        // if the current chars in a word or line are above the max, end the program
        if (charsInCurrWord > MAX_WORD_LENGTH) {
            return 1;
        }
        if (charsInLine > MAX_STRING_LENGTH) {
            return 1;
        }

        // get the next char
        scanf("%c", &currChar);
    }

    poemPtr = realloc(poemPtr, sizeof(char) * (currPos + 1));
    poemPtr[currPos] = '\0';

    // if there is more then 1 word print plural, otherwise print singular
    if (totalWords > 1) {
        printf("%d words on ", totalWords);
    }
    else {
        printf("%d word on ", totalWords);
    }

    // if there is more then 1 word print plural, otherwise print singular
    if (numberOfLines > 1) {
        printf("%d lines\n", numberOfLines);
    }
    else {
        printf("%d line\n", numberOfLines);
    }

    // print the words per line
    for (i = 0; i < numberOfLines; i++) {
        printf("%d ", wordsPerLine[i]);
    }

    printf("\n");

    // free memory
    free(poemPtr);
    free(wordsPerLine);

    return 0;
}