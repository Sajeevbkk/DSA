#include <stdio.h>

int a[100];
int n;

void show() {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quicksort(int low, int high) {
    if (low < high) {
        int pivot = a[high];
        int i = low - 1;

        printf("\nPivot is %d\n", pivot);

        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                printf("Swapped %d and %d: ", a[j], a[i]);
                show();
            }
        }

        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;
        printf("Put pivot %d at spot %d: ", pivot, i + 1);
        show();

        int pi = i + 1;

        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}

int main() {
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nStart: ");
    show();

    quicksort(0, n - 1);

    printf("\nDone: ");
    show();

    return 0;
}