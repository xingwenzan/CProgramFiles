//
// Created by 86159 on 2024-01-20.
// 求组合数 II   https://www.acwing.com/problem/content/888/
// C[a][b] = a!/[(a-b)! * b!] = a! * (a-b)!^(-1) * b!^(-1)
// 预处理出 i! 和 (i!)^(-1) (i! 的逆元 = i 的逆元 * i-1 的逆元 * …… * 1 的逆元)
//
#include "stdio.h"

typedef long long LL;

#define N 100010
const int MOD = 1e9 + 7;
int n, a, b;
int fact[N], infact[N];

int qmi(int base, int index) {
    int ans = 1 % MOD;
    while (index) {
        if (index & 1)ans = (LL) ans * base % MOD;
        base = (LL) base * base % MOD;
        index >>= 1;
    }
    return ans;
}

void init() {
    infact[0] = fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (LL) fact[i - 1] * i % MOD;
        infact[i] = (LL) infact[i - 1] * qmi(i, MOD - 2) % MOD;
    }
}

int main() {
    init();
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", (LL) fact[a] * infact[a - b] % MOD * infact[b] % MOD);
    }
    return 0;
}