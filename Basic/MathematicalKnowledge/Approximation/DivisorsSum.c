//
// Created by 86159 on 2023-11-12.
// 约数之和 https://www.acwing.com/problem/content/873/
//

#include "stdio.h"

#define N 50021
#define null 0x3f3f3f3f
#define mod 1000000007
typedef long long LL;

LL h[N], p[N];   // 哈希表
int n;

void init() {
    for (int i = 0; i < N; ++i) {
        h[i] = null;
        p[i] = 0;
    }
}

int find(int x) {
    int t = x % N;
    while (h[t] != x && h[t] != null) {
        t++;
        if (t >= N)t = 0;
    }
    h[t] = x;
    return t;
}

void get_prime(int x) {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i)continue;
        int t = find(i);
        while (x % i == 0) {
            p[t]++;
            x /= i;
        }
    }
    if (x > 1)p[find(x)]++;
}

LL qmi(LL a, LL k) {
    LL ans = 1 % mod;
    while (k) {
        if (k & 1)ans = ans * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return ans;
}

LL work(LL a, LL k) {
    if (k == 0)return 1;
    if (k % 2 == 0)return (a % mod * (work(a, k - 1)) % mod + 1) % mod;
    return (1 + qmi(a, k / 2 + 1)) % mod * work(a, k / 2) % mod;
}

int main() {
    init();

    scanf("%d", &n);
    int x;
    while (n--) {
        scanf("%d", &x);
        get_prime(x);
    }
    LL ans = 1;
    for (int i = 0; i < N; ++i) {
        // 方法 1 - 直接算
//        LL tmp = 1;
//        while (p[i]--)tmp = (tmp*h[i]+1)%mod;
//        ans = ans * tmp % mod;
        // 方法 2 - 递推
        if (p[i]) ans = ans * work(h[i], p[i]) % mod;
    }
    printf("%lld", ans);
    return 0;
}