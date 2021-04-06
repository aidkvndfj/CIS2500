#include "headerA4.h"

void enqueue(tweet** head, tweet** tail, tweet* node) {
    if (!isEmpty(*head)) {
        (*tail)->next = node;
        *tail = node;
    } else {
        *head = node;
        *tail = node;
    }
}

void dequeue(tweet** head, tweet** tail) {
    tweet *tempHead;

    if (isEmpty(*head)) {
        printf("Nothing to dequeue, queue is empty\n");
        return; 
    }
    
    tempHead = *head;
    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }

    free(tempHead);
}

int isEmpty(tweet* head) {
    if (head == NULL){
        return 1;
    }
    return 0;
}

void printQueue(tweet* head) {
    if (isEmpty(head)){
        printf("Nothing to print, queue is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d: Created by %s: %s\n", head->id, head->user, head->text);
        head = head->next;
    }
    
}
