//
// Created by 86159 on 2023-10-22.
// 二分图的最大匹配 https://www.acwing.com/problem/content/863/
//

#include "stdio.h"
#include "stdbool.h"

#define N 510
#define M 100010

int n1, n2, k;
int h[N], e[M], ne[M], idx = 0;
int choose[N];
bool query[N];

void init() {
    for (int i = 0; i < N; ++i) {
        h[i] = -1;
        choose[i] = 0;
    }
}

void add(int m, int w) {
    e[idx] = w;
    ne[idx] = h[m];
    h[m] = idx++;
}

bool find(int m) {
    for (int i = h[m]; i != -1; i = ne[i]) {
        int w = e[i];
        if (query[w])continue;
        query[w] = true;
        if (choose[w] == 0 || find(choose[w])) {
            choose[w] = m;
            return true;
        }
    }
    return false;
}

int main() {
    init();
    scanf("%d%d%d", &n1, &n2, &k);
    int a, b;
    while (k--) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    int ans = 0;
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j)query[j] = false;
        if (find(i))ans++;
    }
    printf("%d", ans);
    return 0;
}