//
// Created by 86159 on 2024-02-01.
// Nim游戏 https://www.acwing.com/problem/content/893/
// a1^a2^……^an = 0 先手必败
//

#include "stdio.h"

#define N 100010

int stone[N];

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &stone[i]);
        ans ^= stone[i];
    }
    if (ans)puts("Yes");
    else puts("No");
}