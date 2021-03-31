#include <stdio.h>
#include <stdlib.h>

typedef struct microtweet {
    int id;
    char user[51];
    char text[141];
    struct microtweet *next;
} tweet;

void enqueue(tweet **head, tweet **tail, tweet *node);
void dequeue(tweet **head, tweet **tail);
int isEmpty(tweet *head);
void printQueue(tweet *head);

void sortID(tweet **head, tweet **tail);
void reverse(tweet **head, tweet **tail);
void sortUsername(tweet **head, tweet **tail);