//
// Created by 86159 on 2024-02-03.
// 台阶-Nim游戏 https://www.acwing.com/problem/content/894/
// a1 ^ a3 ^ a5 ^ …… ^ an(n 是奇数) = 0   先手必败
//
#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0, x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (i % 2 == 0)ans ^= x;
    }
    if (ans)puts("Yes");
    else puts("No");
}