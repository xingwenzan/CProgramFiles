//
// Created by 86159 on 2023-09-04.
// spfa求最短路 https://www.acwing.com/problem/content/853/
//

#include "stdio.h"
#include "stdbool.h"

#define N 100010
#define INF 0x3f3f3f3f

int h[N], e[N], ne[N], w[N], idx;
int queue[N], hh, tt;
bool state[N];
int dist[N];

bool notEmpty() {
    return hh < tt;
}

void push(int x) {
    queue[tt++] = x;
}

int pop() {
    return queue[hh++];
}

void init() {
    idx = 0;
    hh = 0, tt = 0;
    for (int i = 0; i < N; ++i) {
        h[i] = -1;
        e[i] = ne[i] = w[i] = 0;
        queue[i] = 0;
        state[i] = false;
        dist[i] = INF;
    }
}

void add(int father, int son, int weight) {
    e[idx] = son, w[idx] = weight, ne[idx] = h[father], h[father] = idx++;
}

int spfa(int start, int end) {
    push(start);
    dist[start] = 0;
    state[start] = true;
    while (notEmpty()) {
        int father = pop();
        state[father] = false;
        for (int i = h[father]; i != -1; i = ne[i]) {
            int son = e[i];
            if (dist[son] > dist[father] + w[i]) {
                dist[son] = dist[father] + w[i];
                if (!state[start]) {
                    state[son] = true;
                    push(son);
                }
            }
        }
    }
    return dist[end];
}

int main() {
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int ans = spfa(1, n);
    if (ans == INF)printf("impossible");
    else printf("%d", ans);

    return 0;
}