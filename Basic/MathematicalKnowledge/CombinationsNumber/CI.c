//
// Created by 86159 on 2024-01-17.
// 求组合数 I   https://www.acwing.com/problem/content/887/
// 预处理 C[a][b] = C[a-1][b] + C[a-1][b-1]
//
#include "stdio.h"

#define N 2010
int MOD = 1e9 + 7;
int n;
int c[N][N];

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!j)c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    init();
    scanf("%d", &n);
    int a, b;
    while (n--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }
}