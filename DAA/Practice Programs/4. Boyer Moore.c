#include <limits.h>
#include <string.h>
#include <stdio.h>
#define NO_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

int search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;

    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            // printf("\nPattern occurs at shift = %d", s);
            return s;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }
    return -1;
}

int main()
{
    char txt[50], pat[50];
    printf("Enter the text: ");
    gets(txt);
    printf("\nEnter the pattern: ");
    gets(pat);

    int s = search(txt, pat);

    if (s == -1)
        printf("\nPattern not found!\n");

    else
        printf("\nPattern occurs at shift = %d", s);

    return 0;
}