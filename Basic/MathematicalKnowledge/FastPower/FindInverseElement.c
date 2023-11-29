//
// Created by 86159 on 2023-11-29.
// 快速幂求逆元 https://www.acwing.com/problem/content/878/
//
#include "stdio.h"

typedef long long LL;

int n;

LL qmi(int a, int b, int p) {
    LL ans = 1 % p;
    while (b) {
        if (b & 1)ans = ans * a % p;
        a = a * (LL) a % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    int a, p;
    while (n--) {
        scanf("%d%d", &a, &p);
        if (a % p) {
            printf("%lld\n", qmi(a, p - 2, p));
        } else {
            puts("impossible");
        }
    }
}