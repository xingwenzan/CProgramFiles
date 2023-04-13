//
// Created by 86159 on 2023-04-13.
// 二进制中1的个数 https://www.acwing.com/problem/content/description/803/
//

#include "stdio.h"

int lowBit(int x) { return x & (-x); }

int main() {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        int ans = 0;
        scanf("%d", &x);
        while (x) {
            x -= lowBit(x);
            ans++;
        }
        printf("%d ", ans);
    }
}