//
// Created by 86159 on 2023-10-11.
// Prim算法求最小生成树 https://www.acwing.com/problem/content/860/
//

#include "stdio.h"

#define MIN(i, j) (((i)<(j))?(i):(j))
#define N 510
#define INF 0x3f3f3f3f

int n, m;
int f[N][N];
int st[N], d[N];   // d 代表该点到集合（st==true）的最短距离

void init() {
    for (int i = 0; i < N; ++i) {
        d[i] = INF;
        st[i] = 0;
        for (int j = 0; j < N; ++j) {
            f[i][j] = INF;
        }
    }
}

void add(int u, int v, int w) {
    f[u][v] = f[v][u] = MIN(w, f[u][v]);
}

int prim() {
    /*
     * 可以省去 2 个 if
     * 如果没有，由于 d 全是 INF，第一次（i==0 时）start 一定是 1 且需要额外判定 i!=0
     * 否则结果必然是 INF
     */
    d[1] = 0;
    int ans = 0;   // 用于存放最小生成树
    for (int i = 0; i < n; ++i) {
        int start = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (start == -1 || d[start] > d[j])) start = j;
        }
        if (d[start] == INF)return INF;
        st[start] = 1;
        ans += d[start];
        for (int j = 1; j <= n; ++j) {
            d[j] = MIN(d[j], f[start][j]);
        }
    }
    return ans;
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    int a, b, c;
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int ans = prim();
    if (ans == INF)puts("impossible");
    else printf("%d", ans);
}