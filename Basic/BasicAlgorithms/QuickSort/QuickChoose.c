//
// Created by 86159 on 2023-03-26.
// 第k个数 https://www.acwing.com/problem/content/description/788/
//

#include "stdio.h"

#define N 100010

int q[N];

int quickChoose(int l, int r, int k) {
    if (l >= r) {
        return q[l];
    }
    int i = l - 1, j = r + 1, x = q[(l + r + 1) >> 1];
    while (i < j) {
        while (q[++i] < x) {}
        while (q[--j] > x) {}
        if (i < j) {
            int tmp;
            tmp = q[i], q[i] = q[j], q[j] = tmp;
        }
    }
    if (k <= i - l) {
        return quickChoose(l, i - 1, k);
    } else {
        return quickChoose(i, r, k - (i - l));
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }
    printf("%d", quickChoose(0, n - 1, k));

    return 0;
}