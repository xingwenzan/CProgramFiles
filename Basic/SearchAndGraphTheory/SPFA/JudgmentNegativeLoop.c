//
// Created by 86159 on 2023-09-11.
// spfa判断负环 https://www.acwing.com/problem/content/854/
//

#include "stdio.h"
#include "stdbool.h"

#define N 10010
#define M 10000010

int h[N], e[N], ne[N], w[N], idx;
int queue[M], hh, tt;
bool state[N];
int dist[N], cnt[N];

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
        state[i] = false;
        dist[i] = 0;
        cnt[i] = 0;
    }
}

void add(int father, int son, int weight) {
    e[idx] = son, w[idx] = weight, ne[idx] = h[father], h[father] = idx++;
}

bool spfa(int p) {

    for (int i = 1; i <= p; ++i) {
        push(i);
        state[i] = true;
    }

    while (notEmpty()) {
        int father = pop();
        state[father] = false;
        for (int i = h[father]; i != -1; i = ne[i]) {
            int son = e[i];
            if (dist[son] > dist[father] + w[i]) {
                dist[son] = dist[father] + w[i];
                cnt[son] = cnt[father] + 1;
                if (cnt[son] >= p)return true;
                if (!state[son]) {
                    state[son] = true;
                    push(son);
                }
            }
        }
    }
    return false;
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

    if (spfa(n))puts("Yes");
    else puts("No");

    return 0;
}