//Problem Statement.Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.Input Format.n m,u v w...Output Format.Total weight of MST.Sample Input:4 5, 1 2 3, 1 3 5, 2 3 1, 2 4 4, 3 4 2,Sample Output.6.Explanation.One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>

int main() {
    int n, m;
    int graph[100][100], visited[100] = {0};

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 99999;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    visited[1] = 1;
    int total = 0;

    for (int count = 1; count < n; count++) {
        int min = 99999, x = -1, y = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (y == -1) {
            printf("MST not possible\n");
            return 0;
        }

        total += min;
        visited[y] = 1;
    }

    printf("%d\n", total);

    return 0;
}

