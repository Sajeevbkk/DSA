/* Using stack*/

#include "6_stack.h"

int main() {
    struct Stack s;
    s.top = -1; // Initialize stack top

    unsigned short repeat = 1, option = 0;

    while (repeat) {
        printf("Choose option\n\t(0-push)\n\t(1-pop)\n\t(2-peek)\n\t(3-exit)\n: ");
        scanf("%hu", &option);

        if (option >= 3) repeat = 0;
        else if (option == 0) {
            int value;
            printf("Enter value to push: ");
            scanf("%d", &value);
            printf("Pushing %d to the stack.....\n", value);
            push(&s, value);
        } else if (option == 1) printf("%d is the poped value.....\n", pop(&s));
        else if (option == 2) printf("%d is the peeked value.....\n", peek(s));
        else printf("Wrong option!! Try again!!\n");
    }

    return 0;
}
