#include "fleschIndex.h"

/*
This function takes a filename of a text file as input, opens and reads the contents of the
file and returns the contents as a string (char *)
*/
char * readFile (char * filename) {
    FILE * inFile = NULL;
    
    inFile = fopen(filename, "r");

    // if file isn't read, return null
    if (inFile == NULL) {
        return NULL;
    }

    char * fileString;
    char currChar;
    int numChar;

    numChar = 0;
    fileString = malloc(sizeof(char));

    // while not at end of file
    while(!feof(inFile) && inFile != NULL) {
        // get a char
        fscanf(inFile, "%c", &currChar);
        // add the char to the end of the array
        fileString[numChar] = currChar;

        // add 1 to numchar, realloc filestring for the next loopthrough.
        numChar += 1;
        fileString = realloc(fileString, sizeof(char) * (numChar + 1));
    }

    fileString[numChar] = '\0';

    // close the file
    fclose(inFile);

    return fileString;
}

/*
    Take the total syllables, words, and sentences and uses the equation given in A2.pdf to calculate
    the flesch index. Will return a int that is the flesch index.
*/
int calculateFleschIndex(int syllables, int words, int sentences) {
    float index;
    
    index = 206.835 - 84.6 * (syllables / words) - 1.015 * (words / sentences);

    return round(index);
}

/*
    This function prints the results on standard output (stdout) as the following:
    1.The Flesch/legibility index that you have computed
    2.The number of syllables in the input
    3.The number of words in the input
    4.The number of sentences in the input
*/
void outputFormattedFleschScores(int syllables, int words, int fleschIndex, int sentenceCount) {
    printf("Flesch Index = %d\n", fleschIndex);
    printf("Syllable Count = %d\n", syllables);
    printf("Word Count = %d\n", words);
    printf("Sentence Count = %d\n", sentenceCount);
}

/*
    Takes in a char, and will return 1(true) if the character is one of the specified
    puncuations. It will return 0(false) if it doesn't
*/
int isPunctuation(char character) {
    if (character == '.' || character == ':' || character == ';' || character == '?' || character == '!') {
        return 1;
    }
    
    return 0;
}

/*
    Takes in a char, and will return 1(true) if the character is part of the alphabet.
    It will return 0(false) if it doesn't
*/
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

/*
    Takes in a char, and will return 1(true) if the character is one of the specified
    end word chars. It will return 0(false) if it doesn't
*/
int isEndWordChar(char character) {
    if (character == ' ' || character == ',' || character == '\n') {
        return 1;
    } 

    return 0;
}

/*
    Takes in a char, and will return 1(true) if the character is a vowel.
    It will return 0(false) if it doesn't
*/
int isVowel(char character) {
    character = tolower(character);
    if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'y') {
        return 1;
    }

    return 0;
}

/*
    takes in the file text as a string, will loop through the string and count 
    all the words. Will return the total words as an int
*/
int countWords(char * fileText) {
    int totalWords;
    int currChar;

    totalWords = 0;
    currChar = 0;

    //loop through the files text untill it reaches the terminating char(the end)
    while(fileText[currChar + 1] != '\0'){
        // if the current char is a letter, and the next char isn't a end word char or a puncuation, add 1 to words.
        if (isLetter(fileText[currChar]) && (isEndWordChar(fileText[currChar + 1]) || isPunctuation(fileText[currChar + 1]))) {
            totalWords += 1;
        }
        currChar++;
    }
    
    return totalWords;
}

/*
    Takes in the file text as a string, will loop through the string and count
    all the sentences. It will return the total sentences as an int
*/
int countSentences(char * fileText) {
    int totalSentences;
    int currChar;

    totalSentences = 0;
    currChar = 0;

    // loop through the files text until it reaches the terminating char(the end)
    while (fileText[currChar + 1] != '\0') {
        // if the current char is a letter, and the next char is puncuationg, then add 1 to sentences.
        if (isLetter(fileText[currChar]) && isPunctuation(fileText[currChar + 1])) {
            totalSentences += 1;
        }

        currChar++;
    }  

    return totalSentences;
}

/*
    Takes in the file text as a string, will loop through the string and count
    all the syllables in the text. Will return the total syllables as an int.
*/
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

    // loop through the text untill it reaches the terminating char(the end)
    while (fileText[currChar + 1] != '\0') {
        currentChar = fileText[currChar];
        nextChar = fileText[currChar + 1];
        lastChar = fileText[currChar - 1]; 
        
        // if the current char is a voewl, and the previous char isn't a voewl
        if (isVowel(currentChar) && !isVowel(lastChar)) {
            // if the current char is an e, and the next isn't an end word char
            if (currentChar == 'e' && !isEndWordChar(nextChar)) {
                // add 1 to syllables
                totalSyllables += 1;
                syllablesInWord += 1;
            // if the current char is a voewl, and isn't e
            } else if (isVowel(currentChar) && currentChar != 'e') {
                // add 1 to syllables
                totalSyllables += 1;
                syllablesInWord += 1;
            }
            resetWordSyllable = 1;
        }

        currChar += 1;
        
        // if the current char is a end words char, and flag to reset the words syllables is true
        if (isEndWordChar(currentChar) && resetWordSyllable) {
            // if the syllables in the word is 1
            if (syllablesInWord == 0) {
                // add 1 to syllables
                totalSyllables += 1;
            }
            //reset the syllables in the current word.
            syllablesInWord = 0;
            resetWordSyllable = 0;
        }
    }

    return totalSyllables;

}