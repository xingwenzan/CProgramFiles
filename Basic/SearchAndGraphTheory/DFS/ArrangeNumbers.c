//
// Created by 86159 on 2023-06-23.
// 排列数字 https://www.acwing.com/problem/content/844/
//

#include "stdio.h"
#include "stdbool.h"

int n, arrangement[10];
bool state[10];

void dfs(int p) {
    if (p == n) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", arrangement[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!state[i]) {
            arrangement[p] = i + 1;
            state[i] = true;
            dfs(p + 1);
            state[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        state[i] = false;
    }
    dfs(0);
    return 0;
}