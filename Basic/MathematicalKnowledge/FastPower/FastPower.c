//
// Created by 86159 on 2023-11-25.
// 快速幂 https://www.acwing.com/problem/content/877/
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
    int a, b, p;
    while (n--) {
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", qmi(a, b, p));
    }
}