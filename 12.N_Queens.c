#include <stdio.h>
#include <stdlib.h>

// Function to print the solution board
void printSolution(int n, int x[]) {
    char board[20][20];
    
    // Initialize the board with 'x'
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = 'x';
        }
    }

    // Place the queens on the board
    for (int i = 1; i <= n; i++) {
        board[i][x[i]] = 'Q';
    }

    // Print the board
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the current position is safe for placing a queen
int isSafe(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k)) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the N-Queens problem using backtracking
void nQueens(int n) {
    int x[20];
    int k = 1;
    int count = 0;

    x[k] = 0;

    while (k != 0) {
        x[k] += 1;

        while (x[k] <= n && !isSafe(x, k)) {
            x[k] += 1;
        }

        if (x[k] <= n) {
            if (k == n) {
                count++;
                printf("Solution %d:\n", count);
                printSolution(n, x);
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }

    printf("Total solutions: %d\n", count);
}

int main() {
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    nQueens(n);

    return 0;
}
