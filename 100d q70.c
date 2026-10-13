//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.Input:n vertices.m edges (u,v,w)Output:Shortest distances OR NEGATIVE CYCLE
```c
#include <stdio.h>

#define INF 999999

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, src;
    struct Edge edges[1000];
    int dist[100];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    scanf("%d", &src);

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}
```
