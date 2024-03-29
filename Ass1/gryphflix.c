//-------Includes-------//
#include "gryphflix.h"

//-------Functions-------//
/*This function will take in a filename as a string and attempt to create
a FILEpointer out of it. If the file opens successfully, a FILEpointer will
be returned. Otherwise, NULL. You will only open the file for reading, not
writing
*/
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

/*
This function will read movie titles from a FILE pointer variable named file,
line by line, into the movieNames2D array.The function will either return
1(to indicate successful operation) or 0 to represent abnormal exit
*/
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

/*
This function will reviews from a FILEpointer variable named file,
line by line, into the reviewStruct array.The function will either return
1(to indicate successful operation) or 0 to represent abnormal exit
*/
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

/*
This function will finda list of the most critical reviewersandstore them
in array mostCriticalReviewers.A critical reviewer isareviewer who has the
same amount of negative recommendations as the reviewer with the most negative
recommendations.This function will return an intrepresenting the number of
critical reviewers and will storethe names of each critical reviewer using
the mostCriticalReviewersarray parameter.
*/
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

/*
This function will get a list of the most recommended movies. A recommended
movie has the same amount of positive recommendations ('Y' or 'y') as the
movie which has the most amount of positive recommendations. Like
getMostCriticalReviewers(), this function will return an intrepresenting the number
of recommended movies as well as return the names of each recommended movie using
mostRecommendedMovies.
*/
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
This function will predict the future performance of a movie's box office sales.
This will be based solely offa proprietary GryphCinemas™algorithm. 
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

    // count the words with even characters
    for (i = 0; i < numWords; i++) {
        if (numOfCharsInWords[i] % 2 == 0) {
            numWordsWithEvenChar += 1;
        }
    }
    // if the number of words is more then 1, add 1 to score
    if (numWordsWithEvenChar > 1) {
        score += 1;
    }

    // loop through the words
    for (i = 0; i < numWords - 1; i++) {
        // if the number of characters in one of the words isn't the same as the next one, the set allwordssamechar to 0(false)
        if (numOfCharsInWords[i] != numOfCharsInWords[i + 1]) {
            allWordsSameChar = 0;
        }
    }
    // if all words same char is 1(true) add 2 to the score
    if (allWordsSameChar == 1) {
        score += 2;
    }

    // limit the score to a max of 2 and min of -2
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

// Additional
/*
This function will enumerate a movie title's words. You will program functionality
to count the number of words in each movie title as well as count the number of
letters in each word. You can assume well-formatted movie titles consisting of
only letters and spaces, where spaces are used to separate words—there will not
be any movie titles with trailing space or any invalid input
*/
int enumerateMovie(const char movie[MAX_STR], int charCounts[MAX_WORDS]) {
    int i;
    int numWords;

    // set the number for each word to 0
    for (i = 0; i < MAX_WORDS; i++) {
        charCounts[i] = 0;
    }

    numWords = 1;
    for (i = 0; i < strlen(movie); i++) {
        if (movie[i] == ' ') {
            numWords++;
        }
        else {
            charCounts[numWords - 1] += 1;
        }
    }

    return numWords;
}