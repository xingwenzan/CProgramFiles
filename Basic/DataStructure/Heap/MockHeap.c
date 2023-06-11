//
// Created by 86159 on 2023-06-11.
// 模拟堆 https://www.acwing.com/problem/content/841/
//

#include "stdio.h"
#include "string.h"

#define N 100010
/*
 * heap 堆，0 号位代表堆元素数量
 * n2p n2p[k] 代表第 k 个元素对应堆中位置，0 号位无用
 * p2n p2n[k] 代表堆中 k 号位置是第几个插入的元素，0 号位无用
 * cnt 第 k 个数
 */
int heap[N], n2p[N], p2n[N], cnt = 0;

void swap(int a, int b) {
    // 堆中元素换位置
    int tmp = heap[a];
    heap[a] = heap[b], heap[b] = tmp;
    // 交换元素对应第几个插入
    tmp = p2n[a], p2n[a] = p2n[b], p2n[b] = tmp;
    // 交换第几个插入对应的元素位置
    tmp = n2p[p2n[a]], n2p[p2n[a]] = n2p[p2n[b]], n2p[p2n[b]] = tmp;
}

void down(int p) {
    int tmp = p;
    if (p * 2 <= heap[0] && heap[tmp] > heap[p * 2]) { tmp = p * 2; }
    if (p * 2 + 1 <= heap[0] && heap[tmp] > heap[p * 2 + 1]) { tmp = p * 2 + 1; }
    if (tmp != p) {
        swap(p, tmp);
        down(tmp);
    }
}

void up(int p) {
    while (p <= heap[0] && p / 2 > 0 && heap[p] < heap[p / 2]) {
        swap(p, p / 2);
        p /= 2;
    }
}

// 插入操作
void opI(int x) {
    heap[0]++;
    cnt++;
    heap[heap[0]] = x;
    p2n[heap[0]] = cnt;
    n2p[cnt] = heap[0];
    up(heap[0]);
}

// 删除最小值操作
void opDM() {
    swap(1, heap[0]--);
    down(1);
}

// 删除第 k 个插入的数
void opD(int k) {
    int p = n2p[k];
    swap(p, heap[0]--);
    up(p);
    down(p);
}

// 修改第 k 个插入数操作
void opC(int k, int x) {
    int p = n2p[k];
    heap[p] = x;
    up(p);
    down(p);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char op[10];
        scanf("%s", op);
        int k, x;
        if (op[0] == 'I') {
            scanf("%d", &x);
            opI(x);
        } else if (!strcmp(op, "PM")) {
            printf("%d\n", heap[1]);
        } else if (!strcmp(op, "DM")) {
            opDM();
        } else if (op[0] == 'C') {
            scanf("%d%d", &k, &x);
            opC(k, x);
        } else {
            scanf("%d", &k);
            opD(k);
        }
    }
}