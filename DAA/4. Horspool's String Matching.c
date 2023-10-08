#include <stdio.h>
#include <string.h>

int table[1000], count;

void ShiftTableComputation(char p[]) {
    int m = strlen(p);

    for (int i = 0; i < 1000; i++)
        table[i] = m;

    for (int j = 0; j < m - 1; j++)
        table[p[j]] = m - 1 - j;
}

int HPoolStringMatching(char t[], char p[]) {
    int m = strlen(p);
    int n = strlen(t);
    int i = m - 1, k;

    // Shift Table Computation
    ShiftTableComputation(p);

    while (i <= n - 1) {
        k = 0;
        while ((k <= m - 1) && t[i - k] == p[m - 1 - k])
            k++;

        if (k == m)
            return i - m + 1;

        else {
            i += table[t[i]];
            count++;
        }
    }
    return -1;
}

int main() {
    char t[100], p[100];

    printf("Enter the text: ");
    scanf("%[^\n]%*c", t);

    printf("Enter pattern: ");
    scanf("%[^\n]%*c", p);

    int res = HPoolStringMatching(t, p);

    if (res == -1)
        printf("Not found");

    printf("Pattern found at position %d\n", res + 1);
    printf("Number of shifts performed: %d\n", count);

    return 0;
}
