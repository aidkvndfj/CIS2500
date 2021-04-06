#include "helper.h"

void FreeQueue(tweet *head) {
    tweet *tempTweet;
    while (head != NULL) {
        tempTweet = head->next;
        free(head);
        head = tempTweet;
    }
}

void InsertAtBegining(tweet **head, tweet **tail, tweet *newTweet) {
    if (isEmpty(*head)) {
        *head = *tail = newTweet;
    }
    else {
        newTweet->next = *head;
        *head = newTweet;
    }
}

void SwapTweets(tweet *tweet1, tweet *tweet2) {
    int tempID;
    char tempUser[51];
    char tempText[141];

    tempID = tweet1->id;
    strcpy(tempUser, tweet1->user);
    strcpy(tempText, tweet1->text);

    tweet1->id = tweet2->id;
    strcpy(tweet1->user, tweet2->user);
    strcpy(tweet1->text, tweet2->text);

    tweet2->id = tempID;
    strcpy(tweet2->user, tempUser);
    strcpy(tweet2->text, tempText);
}