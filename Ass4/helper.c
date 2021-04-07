#include "helper.h"

// Loops through the queue and frees all the tweets
void FreeQueue(tweet *head) {
    tweet *tempTweet;
    // while the head isn't null, loop and free
    while (head != NULL) {
        tempTweet = head->next;
        free(head);
        head = tempTweet;
    }
}

// will insert a node at the head of the queue.
void InsertAtBegining(tweet **head, tweet **tail, tweet *newTweet) {
    // if the queue is empty, set head and tail to node
    if (isEmpty(*head)) {
        *head = *tail = newTweet;
    }
    // if queue is not empty, add the node to the head.
    else {
        newTweet->next = *head;
        *head = newTweet;
    }
}

// swaps the values of 2 tweets.
void SwapTweets(tweet *tweet1, tweet *tweet2) {
    int tempID;
    char tempUser[51];
    char tempText[141];

    // store tweet 1 in temps
    tempID = tweet1->id;
    strcpy(tempUser, tweet1->user);
    strcpy(tempText, tweet1->text);

    // set tweet 1 to tweet 2
    tweet1->id = tweet2->id;
    strcpy(tweet1->user, tweet2->user);
    strcpy(tweet1->text, tweet2->text);

    // set tweet 2 to temps.
    tweet2->id = tempID;
    strcpy(tweet2->user, tempUser);
    strcpy(tweet2->text, tempText);
}