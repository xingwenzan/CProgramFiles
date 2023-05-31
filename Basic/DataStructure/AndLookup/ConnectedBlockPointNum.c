//
// Created by 86159 on 2023-05-31.
// 连通块中点的数量 https://www.acwing.com/problem/content/839/
//
#include "stdio.h"
#include "string.h"

#define N 100010

int father[N], son[N];

int quickFather(int x) {
    if (father[x] != x) { father[x] = quickFather(father[x]); }
    return father[x];
}

void marry(int a, int b) {
    int fA = quickFather(a), fB = quickFather(b);
    if (fA != fB) {
        father[fA] = father[fB];
        son[fB] += son[fA];
    }
}

int pointNum(int x) {
    return son[quickFather(x)];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        father[i] = i;
        son[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        char op[2];
        int a, b;
        scanf("\n%s", op);
        if (!strcmp(op, "Q2")) {
            scanf("%d", &a);
            printf("%d\n", pointNum(a));
        } else {
            scanf("%d%d", &a, &b);
            if (!strcmp(op, "Q1")) {
                if (quickFather(a) == quickFather(b)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
            } else {
                marry(a, b);
            }
        }
    }
}