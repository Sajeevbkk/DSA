/* Circular Queue Implementation */

#include <stdio.h>
#define MAX 10

struct Queue {
    int front;
    int rear;
    int count;
    int items[MAX];
};

void initializeQueue(struct Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

void enqueue(struct Queue *q, int value) {
    if (q->count >= MAX) {
        printf("Queue Overflow!!\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
}

int dequeue(struct Queue *q) {
    if (q->count <= 0) {
        printf("Queue Underflow!!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return value;
}

int peek(struct Queue q) {
    if (q.count <= 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return q.items[q.front];
}

