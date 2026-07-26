/* Using Circular Queue */

#include "7_queue.h"
#include <stdio.h>

int main() {
    struct Queue q;
    initializeQueue(&q); // Initialize the queue

    unsigned short repeat = 1, option = 0;

    while (repeat) {
        printf("Choose option\n\t(0-enqueue)\n\t(1-dequeue)\n\t(2-peek)\n\t(3-exit)\n: ");
        scanf("%hu", &option);

        if (option >= 3) repeat = 0;
        else if (option == 0) {
            int value;
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            printf("Enqueuing %d to the queue.....\n", value);
            enqueue(&q, value);
        } else if (option == 1) {
            int dequeuedValue = dequeue(&q);
            if (dequeuedValue != -1) {
                printf("%d is the dequeued value.....\n", dequeuedValue);
            }
        } else if (option == 2) {
            int peekedValue = peek(q);
            if (peekedValue != -1) {
                printf("%d is the peeked value.....\n", peekedValue);
            }
        } else {
            printf("Wrong option!! Try again!!\n");
        }
    }

    return 0;
}