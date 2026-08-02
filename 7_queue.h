/* Standard Queue Implementation */

#include <stdio.h>
#define MAX 10

struct Queue {
    int front;
    int rear;
    int items[MAX];
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow!!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow!!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    return value;
}

int peek(struct Queue q) {
    if (q.front == -1 || q.front > q.rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q.items[q.front];
}