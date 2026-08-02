/* Using Standard Queue Implementation */
#include "7_queue.h"

int main() {
    struct Queue q;
    initializeQueue(&q);

    unsigned short repeat = 1, option = 0;
    while (repeat)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
        printf("Enter your option: ");
        scanf("%hu", &option);

        switch (option)
        {
        case 1:
            int value;
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            printf("Dequeued: %d\n", dequeue(&q));
            break;
        case 3:
            printf("Peek: %d\n", peek(q));
            break;
        case 4:
            repeat = 0;
            break;
        default:
            printf("Invalid option!!\n");
        }
    }
    
    return 0;
}