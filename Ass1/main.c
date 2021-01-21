#include "gryphflix.h"

int main(void) {
    // Variables
    int i;
    int numCritReview;
    int numRecMovies;
    char movieNames[NUMBER_MOVIES][MAX_STR];
    char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR];
    char mostRecommendedMovies[NUMBER_REVIEWERS][MAX_STR];
    struct reviewStruct reviews[NUMBER_REVIEWERS];
    FILE* movieFile;
    FILE* reviewFile;

    movieFile = openFileForReading("movies.txt");
    reviewFile = openFileForReading("reviewers.txt");

    printf("Read Movies Result: %d\n", readMovies(movieFile, movieNames));
    for (i = 0; i < NUMBER_MOVIES; i++) {
        printf("%d: %s\n", i + 1, movieNames[i]);
    }

    printf("\nRead Reviewrs Result: %d\n", readReviews(reviewFile, reviews));
    for (i = 0; i < NUMBER_REVIEWERS; i++) {
        printf("\nReviewer: %s\nFeedback 1: %d\nFeedback 2: %d\nFeedback 3: %d\n", reviews[i].reviewer, reviews[i].feedback[0], reviews[i].feedback[1], reviews[i].feedback[2]);
    }

    numCritReview = getMostCriticalReviewers(reviews, mostCriticalReviewers);
    printf("\nNumber of most critical reviewers: %d\n", numCritReview);
    for (i = 0; i < numCritReview; i++) {
        printf("%s\n", mostCriticalReviewers[i]);
    }

    numRecMovies = getMostRecommendedMovies(movieNames, reviews, mostRecommendedMovies);
    printf("\nNumber of most recommended moveis: %d\n", numRecMovies);
    for (i = 0; i < numRecMovies; i++) {
        printf("%s\n", mostRecommendedMovies[i]);
    }

    printf("\nMovie Score Star Wars: %d\n", predictMovie("Star Wars"));
    printf("\nMovie Score Incredibles: %d\n", predictMovie("Incredibles"));
    printf("\nMovie Score Gone with the Wind: %d\n", predictMovie("Gone with the Wind"));

    return 0;
}