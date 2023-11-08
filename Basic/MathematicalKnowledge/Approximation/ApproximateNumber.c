//
// Created by 86159 on 2023-11-08.
// 约数个数 https://www.acwing.com/problem/content/872/
//

#include "stdio.h"

#define N 50022
#define MOD 1000000007
#define null -1
typedef long long LL;

int n;
int h[N], p[N];   // 哈希表

void init() {
    for (int i = 0; i < N; ++i) {
        h[i] = null;
        p[i] = 0;
    }
}

int find(int x) {
    int t = x % N;
    while (h[t] != x && h[t] != null) {
        if (t >= N)t = 0;
        t++;
    }
    h[t] = x;
    return t;
}

void get_prime(int x) {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i)continue;
        int t = find(i);
        while (x % i==0) {
            p[t]++;
            x /= i;
        }
    }
    if (x > 1)p[find(x)]++;
}

LL get_ans() {
    LL ans = 1;
    for (int i = 0; i < N; ++i) {
        if (h[i] == null)continue;
        ans = ans * (p[i] + 1) % MOD;
    }
    return ans;
}

int main() {
    init();
    scanf("%d", &n);
    int x;
    while (n--) {
        scanf("%d", &x);
        get_prime(x);
    }
    printf("%lld", get_ans());
}