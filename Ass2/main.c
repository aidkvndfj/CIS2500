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

    if (fileText == NULL) {
        printf("ERROR READING FILE \"%s\"", argv[1]);
        return 1;
    }

    printf("%s", fileText);
    totalWords = countWords(fileText);
    totalSentences = countSentences(fileText);
    totalSyllables = countSyllables(fileText);
    fleschIndex = calculateFleschIndex(totalSyllables, totalWords, totalSentences);
    outputFormattedFleschScores(totalSyllables, totalWords, fleschIndex, totalSentences);


    free(fileText);
    return 0;
}
