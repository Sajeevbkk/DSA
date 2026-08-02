/* Using Double Ended Queue Implementation */

#include "9_dequeue.h"

int main() {
    struct Deque dq;
    initializeDeque(&dq);

    unsigned short repeat = 1, option = 0;

    while (repeat) {
        printf("Choose option\n\t(0-insertFront)\n\t(1-insertRear)\n\t(2-deleteFront)\n\t(3-deleteRear)\n\t(4-exit)\n: ");
        scanf("%hu", &option);

        if (option >= 4) repeat = 0;
        else if (option == 0) {
            int value;
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            printf("Inserting %d at the front of the deque.....\n", value);
            insertFront(&dq, value);
        } else if (option == 1) {
            int value;
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            printf("Inserting %d at the rear of the deque.....\n", value);
            insertRear(&dq, value);
        } else if (option == 2) {
            int deletedValue = deleteFront(&dq);
            if (deletedValue != -1) {
                printf("%d is the deleted value from front.....\n", deletedValue);
            }
        } else if (option == 3) {
            int deletedValue = deleteRear(&dq);
            if (deletedValue != -1) {
                printf("%d is the deleted value from rear.....\n", deletedValue);
            }
        } else {
            printf("Wrong option!! Try again!!\n");
        }
    }

    return 0;
}