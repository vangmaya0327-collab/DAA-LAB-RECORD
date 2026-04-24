#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 6

int min_dist(int dist[], bool visited[]) {
    int min = INT_MAX, idx = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int graph[N][N], int src) {
    int  dist[N];
    bool visited[N];

    for (int i = 0; i < N; i++) {
        dist[i]    = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < N; i++) {
        int u = min_dist(dist, visited);
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printf("Vertex\t\tDistance from Source\n");
    for (int i = 0; i < N; i++)
        printf("%c\t\t%d\n", 'A' + i, dist[i]);
}

int main() {
    int graph[N][N] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
