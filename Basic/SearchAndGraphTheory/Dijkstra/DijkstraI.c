//
// Created by 86159 on 2023-07-07.
// Dijkstra求最短路 I https://www.acwing.com/problem/content/851/
//

#include "stdio.h"
#include "stdbool.h"

#define INF 0x3f3f3f
#define N 510
#define M 10010

int n, m;
int f[N][N], d[N];   // d 存的是 1 到 n 的最小距离
bool st[N];

void init() {
    for (int i = 0; i < N; ++i) {
        st[i] = false;
        d[i] = INF;
        for (int j = 0; j < N; ++j) {
            f[i][j] = INF;
        }
    }
    d[1] = 0;
}

int dijkstra() {
    for (int i = 0; i < n; ++i) {
        int start = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (start == -1 || d[j] < d[start])) {
                start = j;
            }
        }
        st[start] = true;
        for (int end = 1; end <= n; ++end) {
            int tmp = d[start] + f[start][end];
            d[end] = (d[end] < tmp ? d[end] : tmp);
        }
    }
    return d[n] == INF ? -1 : d[n];
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int start, end, length;
        scanf("%d%d%d", &start, &end, &length);
        f[start][end] = (f[start][end] < length ? f[start][end] : length);
    }
    printf("%d", dijkstra());
    return 0;
}