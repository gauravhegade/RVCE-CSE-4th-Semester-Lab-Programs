#include <stdio.h>
#include <stdlib.h>

// insertion sort
void sort(int a[10], int n)
{
    int j, item;
    for (int i = 2; i <= n; i++)
    {

        item = a[i];
        j = i - 1;

        while (j >= 1 && a[j] > item)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = item;
    }
}

int main()
{
    int n, a[10], flag = 0;

    printf("\nEnter the size of array :");
    scanf("%d", &n);

    printf("\nEnter array Elements\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    sort(a, n);

    // checking for duplicates in sorted array
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        printf("\nElements are not unique");

    else
        printf("\nElements are unique");

    return 0;
}
