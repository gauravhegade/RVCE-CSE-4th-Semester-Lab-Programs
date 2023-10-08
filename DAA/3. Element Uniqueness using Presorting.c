#include <stdio.h>
#include <stdlib.h>

// insertion sort
void sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int item = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > item) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = item;
    }
}

int checkDuplicate(int a[], int n) {
    sort(a, n);
    // checking for duplicates in sorted array
    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1])
            return 1;

    return 0;
}

int main() {
    int n, a[10];

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("\nEnter array Elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (checkDuplicate(a, n);)
        printf("\nElements are not unique");
    else
        printf("\nElements are unique");

    return 0;
}
