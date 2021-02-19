#include "fleschIndex.h"

char * readFile (char * filename) {
    FILE * inFile = NULL;
    
    inFile = fopen(filename, "r");

    if (inFile == NULL) {
        return NULL;
    }

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
    return (int)(206.835 - 84.6 * ((float)syllables / (float)words) - 1.015 * ((float)words / (float)sentences));
}

void outputFormattedFleschScores(int syllables, int words, int fleschIndex, int sentenceCount) {
    printf("Flesch Index = %d\n", fleschIndex);
    printf("Syllable Count = %d\n", syllables);
    printf("Word Count = %d\n", words);
    printf("Sentence Count = %d\n", sentenceCount);
}

int isPunctuation(char character) {
    if (character == '.' || character == ':' || character == ';' || character == '?' || character == '!') {
        return 1;
    }
    
    return 0;    
}

int isLetter(char character) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int i;

    for(i = 0; i < strlen(letters); i++) {
        if (character == letters[i]) {
            return 1;
        }
    }
    return 0;
}

int isEndWordChar(char character) {
    if (character == ' ' || character == ',' || character == '\n') {
        return 1;
    } 

    return 0;
}

int isVowel(char character) {
    if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'y') {
        return 1;
    }

    return 0;
}

int countWords(char * fileText) {
    int totalWords;
    int currChar;

    totalWords = 0;
    currChar = 0;

    while(fileText[currChar + 1] != '\0'){
        if (isLetter(fileText[currChar]) && (isEndWordChar(fileText[currChar + 1]) || isPunctuation(fileText[currChar + 1]))) {
            totalWords += 1;
        }
        currChar++;
    }
    
    return totalWords;
}

int countSentences(char * fileText) {
    int totalSentences;
    int currChar;

    totalSentences = 0;
    currChar = 0;

    while (fileText[currChar + 1] != '\0') {
        
        if (isLetter(fileText[currChar]) && isPunctuation(fileText[currChar + 1])) {
            totalSentences += 1;
        }

        currChar++;
    }

    return totalSentences;
}

int countSyllables(char * fileText) {
    int totalSyllables;
    int syllablesInWord;
    int currChar;
    char currentChar;
    char lastChar;
    char nextChar;

    totalSyllables = 0;
    syllablesInWord = 0;
    currChar = 1;

    while (fileText[currChar + 1] != '\0') {
        currentChar = fileText[currChar];
        nextChar = fileText[currChar + 1];
        lastChar = fileText[currChar - 1]; 
        
        if (isVowel(currentChar) && !isVowel(lastChar)) {
            if (currentChar == 'e' && !isEndWordChar(nextChar)) {
                totalSyllables += 1;
                syllablesInWord += 1;
                printf("e chars: '%c%c%c'\n", lastChar, currentChar, nextChar);
            } else if (isVowel(currentChar) && currentChar != 'e') {
                totalSyllables += 1;
                syllablesInWord += 1;
                printf("Voe chars: '%c%c%c'\n", lastChar, currentChar, nextChar);
            }
        }

        currChar += 1;

        //// LOGIC NOT YET DONE
        if (isEndWordChar(currentChar) && (!isEndWordChar(nextChar) ^ !isEndWordChar(lastChar))) {
            if (syllablesInWord == 0) {
                totalSyllables += 1;
                printf("Special Voewl\n");
            }
            syllablesInWord = 0;
        }

        // if (isVowel(currentChar) && (isLetter(lastChar) || isLetter(nextChar))) {
        //     if (isVowel(lastChar) || isVowel(nextChar)) {
        //         currChar++;
        //     }
        //     totalSyllables += 1;
        // }
        // currChar++;
    }

    return totalSyllables;

}