#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[1000];

void ShiftTableComputation(char p[])
{
    int m = strlen(p);

    for (int i = 0; i < 1000; i++)
        table[i] = m;

    for (int j = 0; j < m - 1; j++)
        table[p[j]] = m - 1 - j;
}

int HPoolStringMatching(char p[], char t[])
{
    int j, k;
    int m = strlen(p);
    int n = strlen(t);
    int i = m - 1;

    // Shift Table Computation
    ShiftTableComputation(p);

    while (i <= n - 1)
    {
        k = 0;
        while ((k <= m - 1) && t[i - k] == p[m - 1 - k])
            k++;
        if (k == m)
            return i - m + 1;
        else
            i += table[t[i]];
    }
    return -1;
}

int main()
{
    char str[100], ptr[100];
    int res;

    printf("Enter the text:");
    scanf("%s", str);

    printf("Enter pattern:");
    scanf("%s", ptr);

    res = HPoolStringMatching(ptr, str);

    if (res == -1)
        printf("Not found");

    printf("Pattern found at position %d", res + 1);
}
