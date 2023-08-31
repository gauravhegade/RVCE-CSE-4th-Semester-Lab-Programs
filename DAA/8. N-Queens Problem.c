#include <stdio.h>
#include <stdlib.h>
int x[20];
// k->row i->column
int place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    return 1;
}
void printQueen(int n)
{
    static int count = 1;
    printf("\n\nSolution %d is- \n\n", count++);
    for (int i = 1; i <= n; ++i)
        printf("\t%d", i);

    for (int i = 1; i <= n; ++i)
    {
        printf("\n%d", i);
        for (int j = 1; j <= n; ++j) // for nxn board
        {
            if (x[i] == j)
                printf("\tQ"); // queen at i,j position
            else
                printf("\t-"); // empty slot
        }
    }
}
void NQueen(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
                printQueen(n);
            else
                NQueen(k + 1, n);
        }
    }
}
int main()
{
    int n;

    printf("\nN-QUEEN PROBLEM\n");
    printf("\nEnter the number of queens to be placed - ");
    scanf("%d", &n);

    if (n == 2 || n == 3 || n == 0)
        printf("\nNo solutions possible!!");

    NQueen(1, n);
    printf("\n");

    return (0);
}