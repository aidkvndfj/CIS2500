#include <stdio.h>

typedef struct {
    int stack[6];
    int top;
} Stack;

int pop(Stack* s);
void push(int element, Stack* s);
int peek(Stack s);
void printStack(Stack s);
int isEmpty(Stack s);
void change(Stack* s1);

void enqueue(int element, Stack * s);
int dequeue(Stack * s);

int main() {
    Stack s;

    s.top = -1;

    push(3, &s);
    push(4, &s);
    push(10, &s);
    push(20, &s);

    change(&s);

    printStack(s);
    enqueue(69, &s);
    printStack(s);
    printf("dequeue %d\n", dequeue(&s));
    printStack(s);
    enqueue(69, &s);
    printStack(s);
    printf("dequeue %d\n", dequeue(&s));
    printStack(s);

    return 0;
}

int pop(Stack* s) {
    int element;
    element = s->stack[s->top];
    s->top -= 1;
    return element;
}

void push(int element, Stack* s) {
    s->top += 1;
    s->stack[s->top] = element;
}

int peek(Stack s) {
    return 0;
}

void printStack(Stack s) {
    for (int i = 0; i <= s.top; i++) {
        printf("%d\n", s.stack[i]);
    }
    printf("----------------------\n");
}

int isEmpty(Stack s) {
    if (s.top < 0) {
        return 1;
    } else {
        return 0;
    }
}

void change(Stack* s1) {
    Stack s2;
    int first, second;

    s2.top = -1;
    while(!isEmpty(*s1)) {
        first = pop(s1);
        if (isEmpty(*s1)) {
            push(first, &s2);
        } else {
            second = pop(s1);
            push(second, &s2);
            push(first, &s2);
        }
    }

    while(!isEmpty(s2)) {
        push(pop(&s2), s1);
    }
}

void enqueue(int element, Stack* s) {
    push(element, s);
}

int dequeue(Stack* s) {
    Stack s2;
    int element;
    
    s2.top = -1;
    while(s->top != 0) {
        push(pop(s), &s2);
    }
    element = pop(s);
    while(s2.top != -1) {
        push(pop(&s2), s);
    }

    return element;
}
