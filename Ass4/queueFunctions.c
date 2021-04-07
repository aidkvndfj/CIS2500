#include "headerA4.h"

void enqueue(tweet** head, tweet** tail, tweet* node) {
    // if the queue is not empty, add the node to the tail
    if (!isEmpty(*head)) {
        (*tail)->next = node;
        *tail = node;
    }
    // if the queue is empty, set the head and tail to the new node.
    else {
        *head = node;
        *tail = node;
    }
}

void dequeue(tweet** head, tweet** tail) {
    tweet* tempHead;

    // if the queue is empty, say so and return
    if (isEmpty(*head)) {
        printf("Nothing to dequeue, queue is empty\n");
        return;
    }

    // set the temp to head, and the head to the next node.
    tempHead = *head;
    *head = (*head)->next;

    // know if the head is null, to also set the tail to null
    if (*head == NULL) {
        *tail = NULL;
    }

    // free the removed node.
    free(tempHead);
}

int isEmpty(tweet* head) {
    // if the head is null, queue is empty, return 1
    if (head == NULL) {
        return 1;
    }
    return 0;
}

void printQueue(tweet* head) {
    // if the queue is empty, say so and return
    if (isEmpty(head)) {
        printf("Nothing to print, queue is empty\n");
        return;
    }

    // loop through the queue and print each element.
    while (head != NULL) {
        printf("%d: Created by %s: %s\n", head->id, head->user, head->text);
        head = head->next;
    }
}
