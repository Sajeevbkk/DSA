/* Double Ended Queue Implementation */

#include <stdio.h>
#define MAX 10

struct Deque {
    int front;
    int rear;
    int items[MAX];
};

void initializeDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

void insertFront(struct Deque *dq, int value) {
    if (dq->front == 0) {
        printf("Deque Overflow from front!!\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = value;
}

void insertRear(struct Deque *dq, int value) {
    if (dq->rear == MAX - 1) {
        printf("Deque Overflow from rear!!\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = value;
}

int deleteFront(struct Deque *dq) {
    if (dq->front == -1 || dq->front > dq->rear) {
        printf("Deque Underflow from front!!\n");
        return -1;
    }
    int value = dq->items[dq->front];
    dq->front++;
    return value;
}

int deleteRear(struct Deque *dq) {
    if (dq->front == -1 || dq->front > dq->rear) {
        printf("Deque Underflow from rear!!\n");
        return -1;
    }
    int value = dq->items[dq->rear];
    dq->rear--;
    return value;
}

int getFront(struct Deque dq) {
    if (dq.front == -1 || dq.front > dq.rear) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq.items[dq.front];
}

int getRear(struct Deque dq) {
    if (dq.front == -1 || dq.front > dq.rear) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq.items[dq.rear];
}