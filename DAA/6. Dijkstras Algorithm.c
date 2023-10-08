#include <stdio.h>
#define INF 999

void dijs(int n, int source, int cost[10][10], int distance[],
          int predecessor[]) {
    int v, count, visited[23], min;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;

        // distance to the current node is the cost from the source to the
        // current node
        distance[i] = cost[source][i];

        // if distance is not infinity then there is a path from the source to
        // the current node, so we can set the source as the predecessor of the
        // current node
        if (distance[i] != INF)
            predecessor[i] = source;
    }

    visited[source] = 1;
    distance[source] = 0;
    predecessor[source] = -1;
    count = 1;

    while (count < n) {
        // calculating minimum distances
        min = INF;
        for (int w = 0; w < n; w++) {
            // traverse along the minimum cost path marking nodes as visited on
            // the way
            if (!visited[w] && distance[w] < min) {
                min = distance[w];
                v = w;
            }
        }

        visited[v] = 1;
        count++;

        // relaxation
        for (int w = 0; w < n; w++) {
            // if the current node is not visited and the distance of the
            // previous node and the cost to reach the current node from the
            // previous node is less than the current distance then update the
            // new distance, and set the predecessor of the current node as the
            // previous node
            if (!visited[w] && distance[v] + cost[v][w] < distance[w]) {
                distance[w] = distance[v] + cost[v][w];
                predecessor[w] = v;
            }
        }
    }
}

int main() {
    int n, source, distance[10], cost[10][10], predecessor[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 indexed): ");
    scanf("%d", &source);

    dijs(n, source, cost, distance, predecessor);

    printf("\nShortest paths from node %d are: \n", source);
    printf("\nNode\tDistance\tPath\n");

    for (int i = 0; i < n; i++) {
        if (i != source) {
            printf("%d\t%d", i, distance[i]);
            printf("\t\t%d", i);

            int j = i;

            do {
                j = predecessor[j];
                printf("<-%d", j);
            } while (j != source);

            printf("\n");
        }
    }
    printf("\n");

    return 0;
}

/*

Input Graph:
0 3 1 999 999
3 0 7 5 1
1 7 0 2 999
999 5 2 0 7
999 1 999 7 0

*/