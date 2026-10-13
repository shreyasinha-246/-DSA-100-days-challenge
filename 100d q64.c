//Problem: Perform BFS from a given source using queue.Input:n.adjacency list.source s.Output: BFS traversal order
```c
#include <stdio.h>

int graph[100][100], visited[100], queue[100], n;

void BFS(int s) {
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int m, u, v, s;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    scanf("%d", &s);

    BFS(s);

    return 0;
}
```
