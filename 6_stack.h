/* Implementation of Stack */

#include <stdio.h>
#define MAX 10

struct Stack {
    int top;
    int items[MAX];
};

void push(struct Stack *s, int value) {
    if (s->top == MAX-1) {
        printf("Stack Overflow!!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("\nStack Underflow!!\n\n");
        return -1; // Return an invalid value to indicate underflow
    }
    return s->items[(s->top)--];
}

int peek(struct Stack s) {
    /* TODO: Try call by value of stack */
    if (s.top == -1) {
        printf("\nStack is empty\n\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return s.items[s.top];
}
