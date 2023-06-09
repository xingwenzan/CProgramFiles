//
// Created by 86159 on 2023-06-09.
// 堆排序 https://www.acwing.com/problem/content/840/
//
#include "stdio.h"

#define N 100010

int heap[N];   // 0 号位存堆中元素个数

void down(int p) {
    int tmp = p;
    if (p * 2 <= heap[0] && heap[p * 2] < heap[tmp]) { tmp = p * 2; }
    if (p * 2 + 1 <= heap[0] && heap[p * 2 + 1] < heap[tmp]) { tmp = p * 2 + 1; }
    if (tmp != p) {
        int e = heap[p];
        heap[p] = heap[tmp], heap[tmp] = e;
        down(tmp);
    }
}

void heapInit() {
    for (int i = heap[0] / 2; i > 0; --i) {
        down(i);
    }
}

int heapMin() {
    int ans = heap[1];
    heap[1] = heap[heap[0]--];
    down(1);
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    heap[0] = n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &heap[i]);
    }
    heapInit();
    for (int i = 0; i < m; ++i) {
        printf("%d ", heapMin());
    }
    return 0;
}