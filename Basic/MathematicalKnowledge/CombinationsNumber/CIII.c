//
// Created by 86159 on 2024-01-22.
// 求组合数 III https://www.acwing.com/problem/content/889/
// LUCAS 定理：
// C_a^b ≡ C_{a%p}^{b%p} * C_{a//p}^{b//p} ≡ C_{a%p}^{b%p} * C_{a//p%p}^{b//p%p} * C_{a//p//p}^{b//p//p} ……
//

#include "stdio.h"

typedef long long LL;

int qmi(int a, int b, int p) {
    int ans = 1 % p;
    while (b) {
        if (b & 1)ans = (LL) ans * a % p;
        a = (LL) a * a % p;
        b >>= 1;
    }
    return ans;
}

int C(int a, int b, int p) {
    if (b > a)return 0;
    int ans = 1;
    for (int i = a, j = 1; j <= b; i--, j++) {
        ans = (LL) ans * i % p;
        ans = (LL) ans * qmi(j, p - 2, p) % p;
    }
    return ans;
}

int lucas(LL a, LL b, int p) {
    if (a < p || b < p)return C(a, b, p);
    return (LL) C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() {
    int n, p;
    LL a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld%lld%d", &a, &b, &p);
        printf("%d\n", lucas(a, b, p));
    }
    return 0;
}