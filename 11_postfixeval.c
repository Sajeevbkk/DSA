/* Implementation of Posfix Expression Evaluaution */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

int pop(void) {
    if (top < 0) {
        printf("Error: Invalid postfix expression\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *exp) {
    char *token = strtok(exp, " \t\n");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        } else if (strlen(token) == 1 && strchr("+-*/^", token[0])) {
            if (top < 1) {
                printf("Error: Invalid postfix expression\n");
                exit(1);
            }
            int A = pop();
            int B = pop();
            int result;

            switch (token[0]) {
                case '+':
                    result = B + A;
                    break;
                case '-':
                    result = B - A;
                    break;
                case '*':
                    result = B * A;
                    break;
                case '/':
                    if (A == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    result = B / A;
                    break;
                case '^': {
                    result = 1;
                    for (int i = 0; i < A; i++) {
                        result *= B;
                    }
                    break;
                }
                default:
                    printf("Error: Unknown operator\n");
                    exit(1);
            }
            push(result);
        } else {
            printf("Error: Invalid token\n");
            exit(1);
        }
        token = strtok(NULL, " \t\n");
    }

    if (top != 0) {
        printf("Error: Malformed expression\n");
        exit(1);
    }

    return pop();
}

int main(void) {
    char exp[256];

    if (fgets(exp, sizeof(exp), stdin) != NULL) {
        int result = evaluatePostfix(exp);
        printf("%d\n", result);
    }

    return 0;
}

