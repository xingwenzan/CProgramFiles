//
// Created by 86159 on 2023-10-18.
// 染色法判定二分图 https://www.acwing.com/problem/content/862/
//

#include "stdio.h"
#include "stdbool.h"

#define N 100010
#define M 200010

int n, m;
int h[N], e[M], ne[M], idx = 0;
int color[N];
int q[N];

void init() {
    for (int i = 0; i < N; ++i) {
        h[i] = -1;
        color[i] = 0;
    }
}

void add1(int father, int son) {
    e[idx] = son;
    ne[idx] = h[father];
    h[father] = idx++;
}

void add2(int p1, int p2) {
    add1(p1, p2);
    add1(p2, p1);
}

bool bfs(int st) {
    int hh = 0, tt = 0;
    q[0] = st;
    color[st] = 1;
    while (hh <= tt) {
        int fa = q[hh++];
        int cf = color[fa];   // color of father
        for (int i = h[fa]; i != -1; i = ne[i]) {
            int son = e[i];
//            int cs =  - cf;   // color of son
            if (color[son] == 0) {
                q[++tt] = son;
                color[son] = -cf;
            } else if (color[son] == cf) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    int a, b;
    while (m--) {
        scanf("%d%d", &a, &b);
        add2(a, b);
    }
    bool ans = true;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            if (!bfs(i)) {
                ans = false;
                break;
            }
        }
    }
    if (ans)puts("Yes");
    else puts("No");
}