#include <stdio.h>
#define INF 999

int main() {
    int n = 4;
    int g[4][4] = {
        {0, 5, INF, 10},
        {5, 0, 3, INF},
        {INF, 3, 0, 1},
        {10, INF, 1, 0}
    };

    int dist[4] = {0, INF, INF, INF};
    int visited[4] = {0};
    int i, j, u, min;

    for (i = 0; i < n - 1; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && dist[u] + g[u][j] < dist[j])
                dist[j] = dist[u] + g[u][j];
        }
    }

    for (i = 0; i < n; i++)
        printf("Distance from 0 to %d = %d\n", i, dist[i]);

    return 0;
}
