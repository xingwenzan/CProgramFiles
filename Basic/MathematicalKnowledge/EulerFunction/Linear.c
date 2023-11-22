//
// Created by 86159 on 2023-11-22.
// 筛法求欧拉函数 https://www.acwing.com/problem/content/876/
//
#include "stdio.h"
#include "stdbool.h"

#define N 1000010
typedef long long LL;

int n;
int euler[N];
int prime[N], cnt = 0;
bool st[N];

void get_euler() {
    euler[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {   // 质数
            prime[cnt++] = i;
            euler[i] = i - 1;   // 质数的欧拉函数为其 -1
        }
        for (int j = 0; prime[j] <= n / i; ++j) {
            int t = i * prime[j];
            st[t] = true;
            if (i % prime[j] == 0) {
                euler[t] = euler[i] * prime[j];
                break;
            }
            euler[t] = euler[i] * (prime[j] - 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    get_euler();
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += euler[i];
    }

    printf("%lld", ans);
}