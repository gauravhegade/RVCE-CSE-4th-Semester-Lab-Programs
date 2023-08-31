#include "stdio.h"
#include "stdlib.h"

#define SIZE 10001
int count;

void merge(int A[SIZE], int low, int mid, int high)
{
    int B[SIZE];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
            count++;
        }

        else{
            B[k++] = A[j++];
            count++;
        }
    }

    while (i <= mid)
        B[k++] = A[i++];

    while (j <= high)
        B[k++] = A[j++];

    for (i = low; i < k; i++)
        A[i] = B[i];
}

void mergesort(int A[SIZE], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main(){
    int A[SIZE], X[SIZE], Y[SIZE], Z[SIZE];
    int n, i, j, c1, c2, c3;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("\nEnter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("\nArray elements before sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    mergesort(A, 0, n - 1);

    printf("\nArray elements after sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\nBasic operation executed %d times", count);

    printf("\nCount table: ");
    printf("\nSize \t Ascending \t Descending \t Random \t\n");

    for (i = 16; i < SIZE; i *= 2){
        for (j = 0; j < i; j++){
            X[j] = i;
            Y[j] = i - j - 1;
            Z[j] = rand() % i;
        }

        count = 0;
        mergesort(X, 0, i - 1);
        c1 = count;

        count = 0;
        mergesort(Y, 0, i - 1);
        c2 = count;

        count = 0;
        mergesort(Z, 0, i - 1);
        c3 = count;

        printf("%d \t %d \t\t %d \t\t %d \t\n", i, c1, c2, c3);
    }
    return 0;
}
