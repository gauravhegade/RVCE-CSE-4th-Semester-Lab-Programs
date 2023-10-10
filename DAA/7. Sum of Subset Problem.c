#include <stdio.h>
#include <stdlib.h>

int set[10];
int included[10]; // boolean array which tells if element is part of the subset
                  // or not
int max;          // max value received when element is added in the subset

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void subsetSum(int subset, int k, int r) {
    int i;
    static int subset_count = 1; // number of subsets
    included[k] = 1;

    if (set[k] + subset == max) {
        printf("\nSubset %d) ", subset_count++);
        for (int i = 1; i <= k; i++)
            if (included[i])
                printf("%d\t", set[i]);
    }

    else if (subset + set[k] + set[k + 1] <= max)
        subsetSum(subset + set[k], k + 1, r - set[k]);
  
    if ((subset + r - set[k] >= max) && (subset + set[k + 1] <= max)) {
        included[k] = 0;
        subsetSum(subset, k + 1, r - set[k]);
    }
}

int main() {
    int n, i, sum = 0;

    printf("\nSubset Problem\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter elements of the set: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &set[i]);
        sum += set[i];
    }

    // sort array for easy computation
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i; j++)
            if (set[j] > set[j + 1])
                swap(&set[j], &set[j + 1]);

    printf("\nElements of the set are: ");
    for (int i = 1; i <= n; i++)
        printf("%d\t", set[i]);

    printf("\nEnter the maximum subset value required: ");
    scanf("%d", &max);

    if (sum < max || set[1] > max) {
        printf("\nNo subsets possible!\n");
        exit(0);
    }

    subsetSum(0, 1, sum);
    printf("\n");

    return 0;
}
