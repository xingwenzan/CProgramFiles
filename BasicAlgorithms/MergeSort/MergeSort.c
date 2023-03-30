//
// Created by 86159 on 2023-03-27.
// 归并排序 https://www.acwing.com/problem/content/789/
//

#include "stdio.h"

#define N 100010

int q[N], n;

void merge(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1, k = 0, tmp[r - l + 1];
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        } else {
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    while (j <= r) {
        tmp[k++] = q[j++];
    }
    for (int m = l, p = 0; m <= r; ++m, ++p) {
        q[m] = tmp[p];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }
    merge(0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", q[i]);
    }
}