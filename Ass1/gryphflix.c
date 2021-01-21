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
                             char mostRecommendedMovies[NUMBER_REVIEWERS][MAX_STR]) {
    int i;
    int j;
    int maxNumOfY;
    int currNumOfY;
    int listCounter;

    // go through the reviewers and determine the max number of ys
    maxNumOfY = 0;
    // loop through the movies
    for (i = 0; i < NUMBER_MOVIES; i++) {
        currNumOfY = 0;
        // loop through the reviewers
        for (j = 0; j < NUMBER_REVIEWERS; j++) {
            // if the reviewrs game a move a y(1) add 1 to currenumofy
            if (tolower(reviews[j].feedback[i]) == 1) {
                currNumOfY++;
            }
        }

        // if the num of y is greater then the current max, then make the max, the current ys
        if (currNumOfY > maxNumOfY) {
            maxNumOfY = currNumOfY;
        }
    }

    // go through the reviewers and determine the moveis with the max ys
    listCounter = 0;
    // loop through the movies
    for (i = 0; i < NUMBER_MOVIES; i++) {
        currNumOfY = 0;
        // loop through the reviewers
        for (j = 0; j < NUMBER_REVIEWERS; j++) {
            // if the reviewrs game a move a y(1) add 1 to currenumofy
            if (tolower(reviews[j].feedback[i]) == 1) {
                currNumOfY++;
            }
        }

        // if the num of y is the max, then add it to the list
        if (currNumOfY == maxNumOfY) {
            strcpy(mostRecommendedMovies[listCounter], movies[i]);
            listCounter++;
        }
    }

    return listCounter;
}

/*
more then 2 words -1
only 1 word -2
more then one word with even number of chars +1
same num of chars in each word +2
*/
int predictMovie(const char movie[MAX_STR]) {
    int i;
    int score;
    int numWords;
    int allWordsSameChar;
    int numWordsWithEvenChar;
    int numOfCharsInWords[MAX_WORDS];

    // by default we assume that all the words have the same number of chars in them
    allWordsSameChar = 1;
    // by default the score is 0
    score = 0;
    // by default we assume none of the words have even num of chars
    numWordsWithEvenChar = 0;

    // set the number for each word to 0
    for (i = 0; i < MAX_WORDS; i++) {
        numOfCharsInWords[i] = 0;
    }

    // count the words and the number of characters in each word.
    numWords = 1;
    for (i = 0; i < strlen(movie); i++) {
        if (movie[i] == ' ') {
            numWords++;
        }
        else {
            numOfCharsInWords[numWords - 1] += 1;
        }
    }

    // Determine if the score should be affected based on the first 2 points
    if (numWords == 1) {
        score -= 2;
    }
    else if (numWords > 2) {
        score -= 1;
    }

    for (i = 0; i < numWords; i++) {
        if (numOfCharsInWords[i] % 2 == 0) {
            numWordsWithEvenChar += 1;
        }
    }
    if (numWordsWithEvenChar > 1) {
        score += 1;
    }

    for (i = 0; i < numWords - 1; i++) {
        if (numOfCharsInWords[i] != numOfCharsInWords[i + 1]) {
            allWordsSameChar = 0;
        }
    }
    if (allWordsSameChar == 1) {
        score += 2;
    }

    if (score > 2) {
        return 2;
    }
    else if (score < -2) {
        return -2;
    }
    else {
        return score;
    }
}