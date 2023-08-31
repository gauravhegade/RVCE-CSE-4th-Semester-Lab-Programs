#include "stdio.h"
#include "stdlib.h"
#define SIZE 256

int finalValues[SIZE][SIZE], values[SIZE], weights[SIZE];
int capacity, value;

int max(int a, int b) { return (a > b) ? a : b; }

int MFK(int i, int j) {
  if (i == 0 || j == 0)
    return 0;

  if (finalValues[i][j] < 0) {
    if (j < weights[i])
      value = MFK(i - 1, j);

    else
      value = max(MFK(i - 1, j), MFK(i - 1, j - weights[i]) + values[i]);

    finalValues[i][j] = value;
  }
  return finalValues[i][j];
}

int main() {
  int n;

  printf("Enter Knapsack capacity: ");
  scanf("%d", &capacity);

  printf("Enter no. of objects: ");
  scanf("%d", &n);

  printf("Enter values of %d objects: ", n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &values[i]);

  printf("Enter weights of %d objects: ", n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &weights[i]);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= capacity; j++)
      finalValues[i][j] = -1;

  printf("Final value is: %d\n", MFK(n, capacity));

  printf("Table values are: \n");
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= capacity; j++)
      printf("%d\t", finalValues[i][j]);

    printf("\n");
  }

  return 0;
}