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

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data])
            dfs(temp->data, adj, visited);
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* t1 = createNode(v);
        t1->next = adj[u];
        adj[u] = t1;

        struct Node* t2 = createNode(u);
        t2->next = adj[v];
        adj[v] = t2;
    }

    int visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    dfs(1, adj, visited);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");

    return 0;
}