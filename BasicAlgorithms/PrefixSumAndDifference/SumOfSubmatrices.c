//
// Created by 86159 on 2023-04-08.
// 子矩阵的和 https://www.acwing.com/problem/content/798/
//

#include "stdio.h"

#define N 1010

int s[N][N];

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &s[i][j]);
            s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
        }
    }
    int x1, x2, y1, y2;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
    }
    return 0;
}