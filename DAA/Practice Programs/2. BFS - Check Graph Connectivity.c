#include <stdio.h>
#include <stdlib.h>

void bfs(int a[10][10], int n, int visited[10], int source)
{
    int q[10], front = 0, rear = -1;
    int node, i;

    visited[source] = 1;
    q[++rear] = source;
    while (front <= rear)
    {
        node = q[front++];
        for (i = 0; i < n; i++)
        {
            // if there is an edge and the node is not visited
            if (a[node][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
    }
}

int main()
{
    int n, source, i, j, count;
    int a[10][10], visited[10] = {0};

    printf("Enter no of nodes: ");
    scanf("%d", &n);

    printf("\nEnter Adjacency matrix \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    count = 0;
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(a, n, visited, i);
            count++;
        }
    }
    if (count == 1)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is NOT connected with %d components\n", count);

    return 0;
}