//
// Created by 86159 on 2023-06-24.
// n-皇后问题 https://www.acwing.com/problem/content/845/
//

#include "stdio.h"
#include "stdbool.h"

#define N 10
char cb[N][N];   // Chess board
bool col[N], dg[2 * N], udg[2 * N];   // Diagonal 对角线

void init(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cb[i][j] = '.';
        }
    }
    for (int i = 0; i < N; ++i) {
        col[i] = false;
    }
    for (int i = 0; i < 2 * N; ++i) {
        dg[i] = udg[i] = false;
    }
}

void dfs(int p, int n) {
    if (p == n) {
        for (int i = 0; i < n; ++i) {
            puts(cb[i]);
        }
        puts("");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!(col[i] || dg[p + i] || udg[n - p + i])) {
            cb[p][i] = 'Q';
            col[i] = dg[p + i] = udg[n - p + i] = true;
            dfs(p + 1, n);
            cb[p][i] = '.';
            col[i] = dg[p + i] = udg[n - p + i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init(n);
    dfs(0, n);
    return 0;
}