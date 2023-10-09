#include <stdio.h>
#include <string.h>

#define SIZE 1000

int table[SIZE];
int indices[SIZE]; // Array to store the indices of pattern occurrences
int j, i, shifts;

void shiftTable(char p[]) {
    int m = strlen(p);

    for (int i = 0; i < SIZE; i++)
        table[i] = m;

    for (int j = 0; j < m - 1; j++)
        table[p[j]] = m - 1 - j;
}

void horspoolMatching(char t[], char p[]) {
    int n = strlen(t);
    int m = strlen(p);

    i = m - 1;
    int k;

    shiftTable(p);

    while (i < n) {
        k = 0;

        while (k < m && p[m - 1 - k] == t[i - k])
            k++;

        if (k == m) {
            indices[j++] = i - m + 1;
            i += table[t[i]];
            shifts++;
        } else {
            i += table[t[i]];
            shifts++;
        }
    }
}

int main() {
    char p[SIZE], t[SIZE];

    printf("Enter text: ");
    scanf("%[^\n]%*c", t);

    printf("Enter pattern: ");
    scanf("%[^\n]%*c", p);

    j = 0;

    horspoolMatching(t, p);

    if (j == 0) {
        printf("Pattern not found in text");
    } else {
        printf("Pattern found at indices: ");
        for (int i = 0; i < j; i++) {
            printf("%d", indices[i]);
            if (i < j - 1)
                printf(", ");
        }
        printf("\nNumber of shifts performed are: %d\n", shifts);
    }

    printf("\n");
    return 0;
}
