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

int dfs(int v, struct Node* adj[], int visited[], int rec[]) {
    visited[v] = 1;
    rec[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->data;

        if (!visited[u] && dfs(u, adj, visited, rec))
            return 1;
        else if (rec[u])
            return 1;

        temp = temp->next;
    }

    rec[v] = 0;
    return 0;
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

    int visited[n], rec[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        rec[i] = 0;
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, rec)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}