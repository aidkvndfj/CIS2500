#include "gryphflix.h"

int main(void) {
    // Variables
    int i;
    int numCritReview;
    char movieNames[NUMBER_MOVIES][MAX_STR];
    char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR];
    struct reviewStruct reviews[NUMBER_REVIEWERS];
    FILE* movieFile;
    FILE* reviewFile;

    movieFile = openFileForReading("movies.txt");
    reviewFile = openFileForReading("reviewers.txt");

    printf("Read Movies Result: %d\n", readMovies(movieFile, movieNames));
    for (i = 0; i < NUMBER_MOVIES; i++) {
        printf("%d: %s\n", i + 1, movieNames[i]);
    }

    printf("\n");

    printf("Read Reviewrs Result: %d\n", readReviews(reviewFile, reviews));
    for (i = 0; i < NUMBER_REVIEWERS; i++) {
        printf("\nReviewer: %s\nFeedback 1: %d\nFeedback 2: %d\nFeedback 3: %d\n", reviews[i].reviewer, reviews[i].feedback[0], reviews[i].feedback[1], reviews[i].feedback[2]);
    }

    numCritReview = getMostCriticalReviewers(reviews, mostCriticalReviewers);
    printf("Number of most critical reviewers: %d\n", numCritReview);
    for (i = 0; i < numCritReview; i++) {
        printf("%s\n", mostCriticalReviewers[i]);
    }

    return 0;
}