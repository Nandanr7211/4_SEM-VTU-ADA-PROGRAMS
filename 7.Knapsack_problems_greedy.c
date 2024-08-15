#include <stdio.h>
#include <stdlib.h>

void knapsack(int n, int item[], float weight[], float profit[], float capacity) {
    float tp = 0, u;
    int i;
    float x[20];

    u = capacity;
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > u) {
            break;
        } else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n) {
        x[i] = u / weight[i];
    }
    tp = tp + (x[i] * profit[i]);

    printf("Result vector (item : fraction included):\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: %f\n", item[i], x[i]);
    }

    printf("Maximum profit is: %f\n", tp);
}

int main() {
    float weight[20], profit[20], ratio[20], capacity, temp;
    int n, i, j, item[10];

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter item number, weight, and profit:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %f %f", &item[i], &weight[i], &profit[i]);
    }

    printf("Enter maximum capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items based on profit/weight ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                // Swap items
                int tempItem = item[j];
                item[j] = item[i];
                item[i] = tempItem;
            }
        }
    }

    knapsack(n, item, weight, profit, capacity);

    return 0;
}
