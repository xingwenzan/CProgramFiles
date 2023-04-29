//
// Created by 86159 on 2023-04-29.
// 单调栈 https://www.acwing.com/problem/content/832/
//

#include "stdio.h"

#define N 100010

int stack[N], idx = -1;

int push(int x) {
    while (idx >= 0) {
        if (x > stack[idx]) {
            stack[++idx] = x;
            return stack[idx - 1];
        } else {
            idx--;
        }
    }
    stack[++idx] = x;
    return -1;
}


int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        printf("%d ", push(x));
    }
}