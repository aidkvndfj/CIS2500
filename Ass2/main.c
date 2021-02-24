#include "fleschIndex.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("ERROR | USAGE: ./fleschIndex <filename>.\n");
        return 1;
    }

    char * fileText;
    int totalWords;
    int totalSentences;
    int totalSyllables;
    int fleschIndex;

    fileText = readFile(argv[1]);

    // if the file is null, exit the program
    if (fileText == NULL) {
        printf("ERROR READING FILE \"%s\"", argv[1]);
        return 1;
    }

    printf("%s", fileText);

    // get total words
    totalWords = countWords(fileText);
    // get total sentences
    totalSentences = countSentences(fileText);
    // get total syllables
    totalSyllables = countSyllables(fileText);
    // free the memory
    free(fileText);
    // get the flesch index
    fleschIndex = calculateFleschIndex(totalSyllables, totalWords, totalSentences);
    // print the info
    outputFormattedFleschScores(totalSyllables, totalWords, fleschIndex, totalSentences);

    return 0;
}
