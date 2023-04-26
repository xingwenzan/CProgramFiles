//
// Created by 86159 on 2023-04-26.
// 模拟队列 https://www.acwing.com/problem/content/831/
//
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#define M 100010

int queue[M], head = 0, tail = 0;

void push(int x) {
    queue[tail++] = x;
}

void pop() {
    head++;
}

bool empty() {
    return head >= tail;
}

int query() {
    return queue[head];
}

int main() {
    int n, x;
    char op[6];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", op);
        if (!strcmp(op, "push")) {
            scanf("%d", &x);
            push(x);
        } else if (!strcmp(op, "pop")) {
            pop();
        } else if (op[0] == 'e') {
            if (empty()) { printf("YES\n"); }
            else { printf("NO\n"); }
        } else {
            printf("%d\n", query());
        }
    }
}