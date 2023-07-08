//
// Created by 86159 on 2023-07-08.
// Dijkstra求最短路 II https://www.acwing.com/problem/content/852/
// 堆优化
//

#include "stdio.h"
#include "stdbool.h"

#define INF 0x3f3f3f3f
#define N 150010
int h[N], e[N], p[N], w[N], idx = 0;
int heap[N][2];   // 堆   h[0][0] 是堆中元素个数   h[x][0] 点号   h[x][1] 距离
int distance[N];
bool state[N];

void init() {
    heap[0][0] = heap[0][1] = 0;
    for (int i = 0; i < N; ++i) {
        h[i] = -1;
        e[i] = p[i] = 0;
        w[i] = distance[i] = INF;
        state[i] = false;
    }
}

void add(int father, int son, int length) {
    e[idx] = son, w[idx] = length, p[idx] = h[father], h[father] = idx++;
}

void swap(int x, int y) {
    int tmp[2];
    tmp[0] = heap[x][0], tmp[1] = heap[x][1];
    heap[x][0] = heap[y][0], heap[x][1] = heap[y][1];
    heap[y][0] = tmp[0], heap[y][1] = tmp[1];
}

void up(int x) {
    while (x <= heap[0][0] && (x >> 1) > 0 && heap[x][1] < heap[x >> 1][1]) {
        swap(x, x >> 1);
        x >>= 1;
    }
}

void down(int x) {
    int y = x;
    if (x * 2 <= heap[0][0] && heap[y][1] > heap[x * 2][1]) { y = x * 2; }
    if (x * 2 + 1 <= heap[0][0] && heap[y][1] > heap[x * 2 + 1][1]) { y = x * 2 + 1; }
    if (y != x) {
        swap(x, y);
        down(y);
    }
}

void addHeap(int x, int length) {
    int tmp = ++heap[0][0];
    heap[tmp][0] = x, heap[tmp][1] = length;
    up(tmp);
}

void poll() {
    int tmp = heap[0][0]--;
    heap[1][0] = heap[tmp][0], heap[1][1] = heap[tmp][1];
    down(1);
}

bool empty() {
    return heap[0][0] <= 0;
}

int dijkstra(int n) {
    distance[1] = 0;
    addHeap(1, distance[1]);
    while (!empty()) {
        int father = heap[1][0], fd = heap[1][1];   // father's distance
        poll();
        if (!state[father]) {
            state[father] = true;
            for (int i = h[father]; i != -1; i = p[i]) {
                int son = e[i], f2s = w[i];   // father to son
                if (distance[son] > fd + f2s) {
                    distance[son] = fd + f2s;
                    addHeap(son, distance[son]);
                }
            }
        }
    }
    return distance[n] == INF ? -1 : distance[n];
}

int main() {
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    printf("%d", dijkstra(n));
    return 0;
}