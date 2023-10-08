#include <stdio.h>
#include <stdlib.h>

int topo[10], k;

void dfs(int a[10][10], int n, int visited[10], int source) {
    visited[source] = 1;

    for (int i = 1; i <= n; i++)
        if (!visited[i] &&
            a[source][i] == 1) // if there is an edge and neighbour not visited
            dfs(a, n, visited, i);

    topo[++k] = source;
}

int main() {
    int n, a[10][10];
    int visited[10] = {0}; // initialize all elements as 0

    printf("\n Enter the no of Vertices : ");
    scanf("%d", &n);

    printf("\n Enter the Adjacency matrix\n");

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(a, n, visited, i);

    printf("\n The topological ordering is\n");
    for (int i = k; i >= 1; i--)
        printf("%d\t", topo[i]);

    return 0;
}
