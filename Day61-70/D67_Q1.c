#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = v;
    t->next = NULL;
    return t;
}

void topoDFS(int v, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data])
            topoDFS(temp->data, adj, visited, stack, top);
        temp = temp->next;
    }

    stack[(*top)++] = v;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* t = createNode(v);
        t->next = adj[u];
        adj[u] = t;
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[1000];
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            topoDFS(i, adj, visited, stack, &top);
    }

    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}