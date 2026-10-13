//Problem: Detect cycle in directed graph using DFS and recursion stack.Output:YES if cycle exists

#include <stdio.h>

int graph[100][100], visited[100], stack[100], n;

int DFS(int v) {
    visited[v] = 1;
    stack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (DFS(i))
                    return 1;
            }
            else if (stack[i]) {
                return 1;
            }
        }
    }

    stack[v] = 0;
    return 0;
}

int main() {
    int m, u, v, cycle = 0;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(i)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}

