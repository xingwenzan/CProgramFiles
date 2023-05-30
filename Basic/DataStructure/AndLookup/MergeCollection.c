//
// Created by 86159 on 2023-05-30.
// 合并集合 https://www.acwing.com/problem/content/838/
//
#include "stdio.h"

#define N 100010
int father[N];

int quickFather(int num) {
    if (father[num] != num) { father[num] = quickFather(father[num]); }
    return father[num];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
    int a, b;
    char op;
    for (int i = 0; i < m; ++i) {
        scanf("\n%c%d%d", &op, &a, &b);
        if (op == 'M') {
            father[quickFather(a)] = quickFather(father[b]);
        } else {
            if (quickFather(a) == quickFather(b)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
}