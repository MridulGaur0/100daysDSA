#include <stdio.h>
#include <limits.h>

int minDist(int dist[], int visited[], int n) {
    int min = INT_MAX, idx = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
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

    int s;
    scanf("%d", &s);

    int dist[n+1], visited[n+1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[s] = 0;

    for (int i = 1; i < n; i++) {
        int u = minDist(dist, visited, n);
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}