//
// Created by 86159 on 2023-07-03.
// 图中点的层次 https://www.acwing.com/problem/content/849/
//

#include "stdio.h"
#include "stdbool.h"

#define N 100010
int distance[N];
int n;
int h[N], e[N], p[N], idx = 0;
int queue[N], head = 0, tail = 0;

void init() {
    for (int i = 0; i < N; ++i) {
        distance[i] = -1;
        h[i] = -1;
    }
}

// 图中添加边
void addG(int father, int son) {
    e[idx] = son, p[idx] = h[father], h[father] = idx++;
}

// 队列里添加点
void addQ(int x) {
    queue[tail++] = x;
}

bool empty() {
    return head >= tail ? true : false;
}

int poll() {
    return queue[head++];
}

int bfs() {
    distance[1] = 0;
    addQ(1);
    while (!empty()) {
        int father = poll();
        for (int i = h[father]; i != -1; i = p[i]) {
            int son = e[i];
            if (distance[son] == -1) {
                distance[son] = distance[father] + 1;
                addQ(son);
            }
        }
    }
    return distance[n];
}

int main() {
    init();
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        addG(a, b);
    }
    printf("%d", bfs());
    return 0;
}