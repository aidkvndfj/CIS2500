#include "gryphflix.h"

int main(void) {
    // Variables
    int i;
    char movieNames[NUMBER_MOVIES][MAX_STR];
    struct reviewStruct reviews[NUMBER_REVIEWERS];
    FILE* movieFile;
    FILE* reviewFile;

    movieFile = openFileForReading("movies.txt");
    reviewFile = openFileForReading("reviewers-short.txt");

    printf("Read Movies Result: %d\n", readMovies(movieFile, movieNames));
    for (i = 0; i < NUMBER_MOVIES; i++) {
        printf("%d: %s\n", i + 1, movieNames[i]);
    }

    printf("\n");

    printf("Read Reviewrs Result: %d\n", readReviews(reviewFile, reviews));
    for (i = 0; i < NUMBER_REVIEWERS; i++) {
        printf("\nReviewer: %s\nFeedback 1: %d\nFeedback 2: %d\nFeedback 3: %d\n", reviews[i].reviewer, reviews[i].feedback[0], reviews[i].feedback[1], reviews[i].feedback[2]);
    }

    return 0;
}