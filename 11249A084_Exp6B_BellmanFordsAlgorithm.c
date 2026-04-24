#include <stdio.h>
#include <limits.h>

#define N 6

int graph[N][N] = {
    {0, 10,  0, 15,  0,  0},
    {0,  0,  0,  5, 10,  0},
    {0,  0,  0,  0,  0, 10},
    {0,  0,  0,  0,  0,  5},
    {0,  0,  0,  0,  0, 10},
    {0,  0,  0,  0,  0,  0}
};

void bellman_ford(int src) {
    int dist[N];

    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < N - 1; i++)
        for (int u = 0; u < N; u++)
            for (int v = 0; v < N; v++)
                if (graph[u][v] && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];

    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++)
            if (graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains a negative weight cycle\n");
                return;
            }

    printf("Vertex\t\tDistance from source\n");
    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX)
            printf("%c\t\t INF\n", 'A' + i);
        else
            printf("%c\t\t %d\n",  'A' + i, dist[i]);
    }
}

int main() {
    bellman_ford(0);
    return 0;
}
