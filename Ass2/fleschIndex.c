#include "fleschIndex.h"

char * readFile (char * filename) {
    FILE * inFile = NULL;
    
    inFile = fopen(filename, "r");

    if (inFile == NULL) {}

    char * fileString;
    char currChar;
    int numChar;

    numChar = 0;
    fileString = malloc(sizeof(char));

    while(!feof(inFile) && inFile != NULL) {
        fscanf(inFile, "%c", &currChar);
        fileString[numChar] = currChar;

        numChar += 1;
        fileString = realloc(fileString, sizeof(char) * (numChar + 1));
    }

    return fileString;
}

int calculateFleschIndex(int syllables, int words, int sentences) {
    return 0;
}

void outputFormattedFleschScores(int syllables, int words, int fleschIndex, int sentenceCount) {

}