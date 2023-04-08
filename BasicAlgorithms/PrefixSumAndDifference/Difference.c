//
// Created by 86159 on 2023-04-08.
// 差分 https://www.acwing.com/problem/content/799/
//

#include "stdio.h"

#define N 100010

int lst[N], add[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &lst[i]);
    }
    int l, r, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &l, &r, &c);
        add[l] += c;
        add[r + 1] -= c;
    }
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
        tmp += add[i];
        lst[i] += tmp;
        printf("%d ", lst[i]);
    }
}