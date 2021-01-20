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

    // make sure there is a file
    if (file == NULL) {
        return 0;
    }

    //set num movies to 0
    numMovies = 0;
    while (!feof(file)) {
        // if the number of movies counted, is less then the number of movies
        if (numMovies < NUMBER_MOVIES) {
            // get the movie name and remove the newline
            fgets(movieNames[numMovies], MAX_STR, file);
            strtok(movieNames[numMovies], "\n");
        }
        else {
            // otherwise just throw the data into a variable that won't be used else where
            fgets(throwAwayData, MAX_STR, file);
        }
        numMovies++;
    }

    // if the number of movies counted is the same as the expected
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

    // make sure there is a file
    if (file == NULL) {
        return 0;
    }

    numReviews = 0;
    while (!feof(file)) {
        //clear old values
        strcpy(tempReviewer, "");
        for (i = 0; i < NUMBER_MOVIES; i++) {
            tempFeedback[i] = ' ';
        }

        // scan the line and put the reivewer and the feedback into temp variables
        fscanf(file, "%s", tempReviewer);
        for (i = 0; i < NUMBER_MOVIES; i++) {
            fscanf(file, " %c", &tempFeedback[i]);
        }

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
    }

    // if the correct reviews where procesed, return 1, else return 0
    if (numReviews == NUMBER_REVIEWERS + 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS],
                             char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]) {
    // Variables
    int i;
    int j;
    int maxNumOfN;
    int currNumOfN;
    int listCounter;

    // go through the reviewers and find the max number of n
    maxNumOfN = 0;
    // loop through reviewers
    for (i = 0; i < NUMBER_REVIEWERS; i++) {
        currNumOfN = 0;
        // loop through the movies
        for (j = 0; j < NUMBER_MOVIES; j++) {
            if (reviews[i].feedback[j] == 0) {
                currNumOfN++;
            }
        }
        // if the current number of ns is greater the the max, replace it
        if (currNumOfN > maxNumOfN) {
            maxNumOfN = currNumOfN;
        }
    }

    // Go through the reviewers again and copy the ones with the max number of ns
    listCounter = 0;
    // loop through the reviewers
    for (i = 0; i < NUMBER_REVIEWERS; i++) {
        currNumOfN = 0;
        // loop through the movies
        for (j = 0; j < NUMBER_MOVIES; j++) {
            if (reviews[i].feedback[j] == 0) {
                currNumOfN++;
            }
        }
        // if the current number of ns of a review is the max, copy the name to the list.
        if (currNumOfN == maxNumOfN) {
            strcpy(mostCriticalReviewers[listCounter], reviews[i].reviewer);
            listCounter++;
        }
    }

    return listCounter;
}

int getMostRecommendedMovies(const char movies[NUMBER_MOVIES][MAX_STR],
                             const struct reviewStruct reviews[NUMBER_REVIEWERS],
                             char mostRecommendedMovies[NUMBER_REVIEWERS][MAX_STR]);
int predictMovie(const char movie[MAX_STR]);