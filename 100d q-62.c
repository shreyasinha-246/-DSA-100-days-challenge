//Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
  
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[100];

void addEdge(int u, int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }

    return 0;
}
```
