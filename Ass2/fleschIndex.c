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

    fclose(inFile);

    return fileString;
}

int calculateFleschIndex(int syllables, int words, int sentences) {
    float index;
    // index = (84.6 * ((float)syllables / (float)words)) - (1.015 * ((float)words / (float)sentences));
    // index = 206.835 - index;

    // index = (84.6 * (syllables / words));
    // index = index - (1.015 * (words / sentences));
    // index = 206.835 - index;

    index = 206.835 - 84.6 * (syllables / words) - 1.015 * (words / sentences);

    return round(index);
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
    character = tolower(character);
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int i;

    for(i = 0; i < 26; i++) {
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
    character = tolower(character);
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
    int resetWordSyllable;
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
                // printf("e chars: '%c%c%c'\n", lastChar, currentChar, nextChar);
            } else if (isVowel(currentChar) && currentChar != 'e') {
                totalSyllables += 1;
                syllablesInWord += 1;
                // printf("Voe chars: '%c%c%c'\n", lastChar, currentChar, nextChar);
            }
            resetWordSyllable = 1;
        }

        currChar += 1;
        
        if (isEndWordChar(currentChar) && resetWordSyllable) {
            if (syllablesInWord == 0) {
                totalSyllables += 1;
                // printf("Special Voewl\n");
            }
            syllablesInWord = 0;
            resetWordSyllable = 0;
        }
    }

    return totalSyllables;

}