//
// Created by 86159 on 2023-10-15.
// Kruskal算法求最小生成树 https://www.acwing.com/problem/content/861/
//
#include "stdio.h"

#define N 100010
#define M 200010
#define INF 0x3f3f3f3f

typedef struct {
    int start;
    int end;
    int weight;
} Edge;   // 边

int father[N];   // 祖宗节点
Edge edge[M];
int n, m;

void init() {
    for (int i = 0; i < N; ++i) {
        father[i] = i;
    }
}

// 找祖宗节点
int find(int x) {
    if (x != father[x]) father[x] = find(father[x]);
    return father[x];
}

void sort(int st, int ed) {
    if (st >= ed)return;
    int mid = edge[(st + ed) >> 1].weight, l = st - 1, r = ed + 1;
    while (l < r) {
        while (edge[++l].weight < mid);
        while (edge[--r].weight > mid);
        if (l < r) {
            Edge tmp = edge[l];
            edge[l] = edge[r];
            edge[r] = tmp;
        }
    }
    sort(st, r);
    sort(r + 1, ed);
}

int kruskal() {
    int ans = 0, cnt = 0;
    sort(0, m - 1);
    for (int i = 0; i < m; ++i) {
        int a = edge[i].start, b = edge[i].end, w = edge[i].weight;
        int fa = find(a), fb = find(b);
        if (fa != fb) {
            ans += w;
            cnt++;
            father[fa] = fb;
        }
    }
    if (cnt < n - 1)return INF;
    return ans;
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edge[i].start, &edge[i].end, &edge[i].weight);
    }
    int ans = kruskal();
    if (ans == INF)puts("impossible");
    else printf("%d", ans);
    return 0;
}