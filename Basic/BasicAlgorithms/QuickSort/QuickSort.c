//
// Created by 86159 on 2023-03-24.
// 快速排序 https://www.acwing.com/problem/content/787/
// https://www.acwing.com/activity/content/code/content/5198516/
//
#include <stdio.h>

#define N 100010

int q[N], n;

void quickSort(int l, int r) {
    if (l >= r) {
        return;
    }
    int i = l - 1, j = r + 1;
    int x = q[(i + j) >> 1];
    while (i < j) {
        while (q[++i] < x) {}
        while (q[--j] > x) {}
        if (i < j) {
            int t;
            t = q[i];
            q[i] = q[j];
            q[j] = t;
        }
    }
    quickSort(l, j);
    quickSort(j + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }
    quickSort(0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", q[i]);
    }
    return 0;
}