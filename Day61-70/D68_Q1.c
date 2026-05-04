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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int indegree[n];
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* t = createNode(v);
        t->next = adj[u];
        adj[u] = t;

        indegree[v]++;
    }

    int q[1000];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q[rear++] = i;
    }

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0)
                q[rear++] = temp->data;
            temp = temp->next;
        }
    }

    return 0;
}