//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
```c
#include <stdio.h>

#define INF 999999

int graph[100][100], visited[100], dist[100], n;

void dijkstra(int src) {
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1, min = INF;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }
}

int main() {
    int m, u, v, w, src;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    scanf("%d", &src);

    dijkstra(src);

    return 0;
}
```
