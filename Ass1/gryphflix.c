//-------Includes-------//
#include "gryphflix.h"

//-------Functions-------//
FILE *openFileForReading(char *fileName) {
    // open the file
    FILE *outFile = NULL;
    outFile = fopen(fileName, "r");

    // If file is open, return pointer, else return NULL
    if (outFile != NULL) {
        return outFile;
    }
    else {
        return NULL;
    }
}

int readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR]) {
    int numMovies;
    char throwAwayData[MAX_STR];

    if (file == NULL) {
        return 0;
    }

    numMovies = 0;
    while (!feof(file)) {
        printf("Begining: %d\n", numMovies);
        if (numMovies < NUMBER_MOVIES) {
            fgets(movieNames[numMovies], MAX_STR, file);
            strtok(movieNames[numMovies], "\n");
        }
        else {
            fgets(throwAwayData, MAX_STR, file);
        }
        numMovies++;
        printf("End: %d\n", numMovies);
    }

    if (numMovies == NUMBER_MOVIES) {
        return 1;
    }
    else {
        return 0;
    }
}

int readReviews(FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS]) {
    int i;
    int numReviews;
    char tempFeedback[NUMBER_MOVIES];
    char tempReviewer[MAX_STR];

    if (file == NULL) {
        return 0;
    }

    numReviews = 0;
    while (!feof(file)) {
        printf("being Loop%d\n", numReviews);
        // scan the line and put the reivewer and the feedback into temp variables
        fscanf(file, "%s %c %c %c", tempReviewer, &tempFeedback[0], &tempFeedback[1], &tempFeedback[2]);

        // if the number of reviews currently read is less then the number of reviewers

        if (numReviews < NUMBER_REVIEWERS) {
            // set the reviewer
            strcpy(reviews[numReviews].reviewer, tempReviewer);

            // loop through the feedback
            for (i = 0; i < NUMBER_MOVIES; i++) {
                // if the feedback is y, set the struct feed back to 1
                if (tolower(tempFeedback[i]) == 'y') {
                    reviews[numReviews].feedback[i] = 1;
                }
                else {
                    reviews[numReviews].feedback[i] = 0;
                }
            }
        }

        numReviews++;
        printf("end Loop%d\n", numReviews);
    }

    // if the correct reviews where procesed, return 1, else return 0
    if (numReviews == NUMBER_REVIEWERS) {
        return 1;
    }
    else {
        return 0;
    }
}

int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS],
                             char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]);
int getMostRecommendedMovies(const char movies[NUMBER_MOVIES][MAX_STR],
                             const struct reviewStruct reviews[NUMBER_REVIEWERS],
                             char mostRecommendedMovies[NUMBER_REVIEWERS][MAX_STR]);
int predictMovie(const char movie[MAX_STR]);