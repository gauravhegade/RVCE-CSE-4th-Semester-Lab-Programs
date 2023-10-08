#include <stdio.h>
#include <stdlib.h>

int x[20];

// k = row
// i = column
int place(int k, int i) {
    for (int j = 1; j < k; j++)
        // if queens are in the same column or
        // if queens are diagonal to each other
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    return 1;
}

void printQueen(int n) {
    static int count = 1;

    printf("\nSolution %d is: \n", count++);

    for (int i = 1; i <= n; ++i)
        printf("\t%d", i);

    for (int i = 1; i <= n; ++i) {
        printf("\n%d", i);
        for (int j = 1; j <= n; ++j) {
            if (x[i] == j)
                printf("\tQ"); // place queen at position i, j
            else
                printf("\t-");
        }
    }
    printf("\n");
}

// k = row number
// i = column number
void NQueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            // place the queen kth row and ith column
            x[k] = i;
            if (k == n)
                printQueen(n);
            else
                NQueen(k + 1, n);
        }
    }
}

int main() {
    int n;

    printf("\nEnter the number of queens to be placed: ");
    scanf("%d", &n);

    if (n == 2 || n == 3 || n == 0)
        printf("\nNo solutions possible!!");

    NQueen(1, n);
    printf("\n");

    return (0);
}