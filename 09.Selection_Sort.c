#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int swap = arr[i];
            arr[i] = arr[min];
            arr[min] = swap;
        }
    }
}

int main() {
    int a[MAX], n;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000; // storing a random number between 0 and 1000
        printf("%d\n", a[i]);
    }

    start = clock();
    selectionSort(a, n);
    end = clock();

    printf("\nThe sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    printf("\nTime taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
