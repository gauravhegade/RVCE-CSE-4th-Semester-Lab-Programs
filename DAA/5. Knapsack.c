#include <stdio.h>
#include <string.h>
#define SIZE 256

int finalValues[SIZE][SIZE], weights[SIZE], values[SIZE];
int value, capacity;

int max(int a, int b) { return a > b ? a : b; }

int MFK(int i, int j){
    if(i == 0 || j == 0)
        return 0;

    if(finalValues[i][j] < 0){
        if(j < weights[i])
            value = MFK(i - 1, j);
        else
            value = max(MFK(i-1, j), values[i] + MFK(i - 1, j - weights[i]));

        finalValues[i][j] = value;
    }
    return finalValues[i][j];
}

int main(){
    int n;
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter profits of %d objects: ", n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &values[i]);

    printf("Enter weights of %d objects: ", n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &weights[i]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= capacity; j++)
            finalValues[i][j] = -1;

    int finalProfit = MFK(n, capacity);

    printf("\nFinal profit is: %d\n", finalProfit);
  
    printf("Selected objects are: ");
    int i = n, j = capacity;

    while(i != 0 && j != 0){
        if(finalValues[i][j] != finalValues[i - 1][j]){
            printf("%d ", i);
            j -= weights[i];
        }
        i--;
    }

    printf("\n\nTable values are: \n");
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= capacity; j++)
            printf("%d\t", finalValues[i][j]);
        printf("\n");
    }
    return 0;
}