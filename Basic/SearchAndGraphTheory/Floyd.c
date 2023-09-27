//
// Created by 86159 on 2023-09-27.
// Floyd求最短路 https://www.acwing.com/problem/content/856/
//
#include "stdio.h"

#define N 210
#define INF 0x3f3f3f3f
#define MIN(i, j) (((i)<(j))?(i):(j))

int n, m, k;
int dist[N][N];

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist[i][j] = i == j ? 0 : INF;
        }
    }
}

void floyd() {
    for (int t = 1; t <= n; ++t) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                dist[i][j] = MIN(dist[i][j], dist[i][t] + dist[t][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    init();
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        dist[a][b] = MIN(dist[a][b], c);
    }

    floyd();

    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &a, &b);
        c = dist[a][b];
        if (c > INF / 2)puts("impossible");
        else printf("%d\n", c);
    }
    return 0;
}