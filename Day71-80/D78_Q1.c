#include <stdio.h>
#include <limits.h>

int minKey(int key[], int mst[], int n) {
    int min = INT_MAX, idx = -1;
    for (int i = 1; i <= n; i++) {
        if (!mst[i] && key[i] < min) {
            min = key[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n+1][n+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[n+1], mst[n+1];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[1] = 0;

    int total = 0;

    for (int i = 1; i <= n; i++) {
        int u = minKey(key, mst, n);
        mst[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !mst[v] && adj[u][v] < key[v])
                key[v] = adj[u][v];
        }
    }

    printf("%d", total);

    return 0;
}