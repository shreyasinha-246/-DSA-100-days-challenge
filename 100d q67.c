//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>

int graph[100][100], visited[100], stack[100];
int n, top = -1;

void DFS(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(i);
        }
    }

    stack[++top] = v;
}

int main() {
    int m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}

