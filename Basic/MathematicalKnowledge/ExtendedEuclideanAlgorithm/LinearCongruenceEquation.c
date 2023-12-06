//
// Created by 86159 on 2023-12-06.
// 线性同余方程 https://www.acwing.com/problem/content/880/
// ax ≡ b(mod m)   等价于   ax%m = b   等价于   ax = my+b   等价于   ax+(my') = b
//

#include "stdio.h"

int n;


int exgcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1, *y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    *y -= a / b * (*x);
    return d;
}

int main() {
    scanf("%d", &n);
    int a, b, m;
    int x = 0, y = 0;
    while (n--) {
        scanf("%d%d%d", &a, &b, &m);
        int gcd = exgcd(a, m, &x, &y);
        if (b % gcd)puts("impossible");
        else printf("%lld\n", (long long) b / gcd * x % m);
    }
}