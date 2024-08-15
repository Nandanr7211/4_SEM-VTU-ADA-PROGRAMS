#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void merge(int a[], int low, int mid, int high) {
    int temp[MAX], i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= high) {
        temp[k++] = a[j++];
    }
    for (i = 0; i < k; i++) {
        a[low + i] = temp[i];
    }
}

void qs(int a[], int low, int high) {
    if (high > low) {
        int mid = (low + high) / 2;
        qs(a, low, mid);
        qs(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[MAX], n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }
    printf("Entered array is\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    qs(a, 0, n - 1);
    printf("\nsorted array is\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
