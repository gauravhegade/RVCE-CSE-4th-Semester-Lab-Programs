#include <stdio.h>
#include <stdlib.h>

int set[10];      // denotes the set s
int included[10]; // boolean array which tells if element is part of the subset or not
int max;          // max value received when element is added in the subset

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void subsetSum(int subset, int k, int r)
{
    int i;
    static int subset_count = 1; // number of subsets
    included[k] = 1;

    // if the weight of the current node and the current subset sum is equal to the required max sum, then print the subset elements
    if (set[k] + subset == max)
    {
        printf("\nSubset %d) ", subset_count++);
        for (int i = 1; i <= k; i++)
            // if that node is part of the subset, then print its value
            if (included[i] == 1)
                printf("%d\t", set[i]);
    }

    // if the sum + weight of the current element and the next element is still less than the max value, recursively call find the next element in the subset
    // r is the total sum of the elements
    else if (subset + set[k] + set[k + 1] <= max)
        subsetSum(subset + set[k], k + 1, r - set[k]);

    // if the subset sum + the total sum - the weight of the current element is exceeding the max sum and if the subset sum + weight of the next element is less than the max required sum do not include that element in the subset
    if ((subset + r - set[k] >= max) && (subset + set[k + 1] <= max))
    {
        included[k] = 0;
        subsetSum(subset, k + 1, r - set[k]);
    }
}

int main()
{
    int n, i, sum = 0;

    printf("\nSubset Problem\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter elements of the set: ");
    for (int i = 1; i <= n; i++)
    {
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

    if (sum < max || set[1] > max)
    {
        printf("\nNo subsets possible!\n");
        exit(0);
    }

    subsetSum(0, 1, sum);
    printf("\n");

    return 0;
}