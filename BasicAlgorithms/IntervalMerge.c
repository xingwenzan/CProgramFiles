//
// Created by 86159 on 2023-04-15.
// 区间合并 https://www.acwing.com/problem/content/805/
//

#include "stdio.h"

#define N 100010

typedef struct {
    int left;
    int right;
} Interval;

Interval interval[N];

void quickSort(int l, int r) {
    if (l >= r) { return; }
    int i = l - 1, j = r + 1, x = interval[(i + j) >> 1].left;
    while (i < j) {
        while (interval[++i].left < x) {}
        while (interval[--j].left > x) {}
        if (i < j) {
            Interval tmp = interval[i];
            interval[i] = interval[j];
            interval[j] = tmp;
        }
    }
    quickSort(l, j);
    quickSort(j + 1, r);
}

void mergeSort(int l, int r) {
    if (l >= r) { return; }
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    Interval tmp[r - l + 1];
    while (i <= mid && j <= r) {
        if (interval[i].left <= interval[j].left) {
            tmp[k++] = interval[i++];
        } else {
            tmp[k++] = interval[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = interval[i++];
    }
    while (j <= r) {
        tmp[k++] = interval[j++];
    }
    for (int m = l, p = 0; m <= r; ++m, ++p) {
        interval[m] = tmp[p];
    }
}

int merge(int l, int r) {
    quickSort(l, r);   // 90 ms
    mergeSort(l, r);   // 99 ms
    Interval tmp[N];
    int length = 0, start = (int) -2e9, end = (int) -2e9;
    for (int i = 0; i < r - l + 1; i++) {
        if (interval[i].left > end) {
            if (start != -2e9) {
                tmp[length].left = start;
                tmp[length].right = end;
                length++;
            }
            start = interval[i].left;
            end = interval[i].right;
        } else {
            end = (end < interval[i].right ? interval[i].right : end);
        }
    }
    if (start != -2e9) {
        tmp[length].left = start;
        tmp[length].right = end;
        length++;
    }
    return length;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &interval[i].left, &interval[i].right);
    }
    printf("%d", merge(0, n - 1));
    return 0;
}