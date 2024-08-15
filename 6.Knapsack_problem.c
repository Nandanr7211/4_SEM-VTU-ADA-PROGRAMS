#include <stdio.h>
#include <stdlib.h>

int w[10], v[10][10], value[10], b[10];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knap(int i, int j) {
    if (i == 0 || j == 0) {
        v[i][j] = 0;
    } else if (j < w[i]) {
        v[i][j] = knap(i - 1, j);
    } else {
        v[i][j] = max(knap(i - 1, j), value[i] + knap(i - 1, j - w[i]));
    }
    return v[i][j];
}

void optimal(int i, int j) {
    if (i >= 1 && j >= 1) {
        if (v[i][j] != v[i - 1][j]) {
            printf("item: %d\n", i);
            b[i] = 1;
            j = j - w[i];
            optimal(i - 1, j);
        } else {
            optimal(i - 1, j);
        }
    }
}

int main() {
    int profit, w1, n, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &w1);

    printf("Enter the values:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter the weights:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    profit = knap(n, w1);
    printf("Profit: %d\n", profit);
    printf("Optimal subset is:\n");

    optimal(n, w1);

    printf("The solution vector is:\n");
    for (i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }

    getchar(); // To pause the program similar to getch()
    return 0;
}
