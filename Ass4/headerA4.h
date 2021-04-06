#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct microtweet {
    int id;
    char user[51];
    char text[141];
    struct microtweet *next;
} tweet;

typedef struct queueStruct {
    int count;
    tweet* front;
    tweet* rear;
} queue;

void enqueue(tweet **head, tweet **tail, tweet *node);
void dequeue(tweet **head, tweet **tail);
int isEmpty(tweet *head);
void printQueue(tweet *head);

void sortID(tweet **head, tweet **tail);
void reverse(tweet **head, tweet **tail);
void sortUsername(tweet **head, tweet **tail);