//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
```c
#include <stdio.h>

int graph[100][100], indegree[100], queue[100];
int n;

void topologicalSort() {
    int front = 0, rear = 0, count = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        for (int i = 0; i < n; i++) {
            if (graph[v][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if (count != n)
        printf("\nCycle detected!");
}

int main() {
    int m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++;
    }

    topologicalSort();

    return 0;
}
```
