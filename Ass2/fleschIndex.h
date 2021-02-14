/*
Student Name: Eric Morse
Student ID: 1141504
Due Date: Feb 28, 2021
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
    1) I have read and understood the policy on academic integrity.
    2) I have completed Moodle's module on academic integrity.
    3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * readFile(char * filename);
int calculateFleschIndex(int syllables, int words, int sentences);
void outputFormattedFleschScores(int syllables, int words, int fleschIndex, int sentenceCount);