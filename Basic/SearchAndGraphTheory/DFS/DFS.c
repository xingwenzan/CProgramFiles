//
// Created by 86159 on 2023-06-30.
// 树与图的深度优先遍历 树的重心 https://www.acwing.com/problem/content/848/
//

#include "stdio.h"
#include "stdbool.h"

#define N 100010
bool st[N];
int n;
int h[N], e[N * 2], p[N * 2], idx = 0;
int ans = N;

void add(int a, int b) {
    e[idx] = b, p[idx] = h[a], h[a] = idx++;
    e[idx] = a, p[idx] = h[b], h[b] = idx++;
}

int dfs(int father) {
    st[father] = true;
    int size = 0, sum = 0;   // 以此点为重心时各连通块最大值   子树节点总数
    for (int i = h[father]; i != -1; i = p[i]) {
        int son = e[i];
        if (st[son]) { continue; }
        int s = dfs(son);   // 该子树节点数
        size = (size > s ? size : s);
        sum += s;
    }
    int tmp = n - sum - 1;
    size = (size > tmp ? size : tmp);
    ans = (ans < size ? ans : size);
    return sum + 1;
}

int main() {
    for (int i = 0; i < N; ++i) {
        h[i] = -1, st[i] = false;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    dfs(1);
    printf("%d", ans);
}