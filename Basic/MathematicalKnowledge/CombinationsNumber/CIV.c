//
// Created by 86159 on 2024-01-25.
// 求组合数 IV https://www.acwing.com/problem/content/890/
// 筛质数 - a!分解 - 高精度计算
// a!分解 https://www.acwing.com/video/309/
//
#include "stdio.h"
#include "stdbool.h"

#define N 5005
#define M 25000000

int prime[N], power[N], idx = 0;
bool st[N];
int ANS[M], size;

void getPrime(int x) {
    for (int i = 2; i <= x; ++i) {
        if (!st[i])prime[idx++] = i;
        for (int j = 0; prime[j] <= x / i; ++j) {
            st[i * prime[j]] = true;
            if (i % prime[j] == 0)break;
        }
    }
}

int getPower(int x, int p) {
    int ans = 0;
    while (x) {
        ans += x / p;
        x /= p;
    }
    return ans;
}

void mul(int x) {
    int tmp = 0;
    for (int i = 0; i <= size; ++i) {
        tmp += ANS[i] * x;
        ANS[i] = tmp % 10;
        tmp /= 10;
    }
    while (tmp) {
        ANS[++size] = tmp % 10;
        tmp /= 10;
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    getPrime(a);
    for (int i = 0; i < idx; ++i) {
        int p = prime[i];
        power[i] = getPower(a, p) - getPower(b, p) - getPower(a - b, p);
    }
    ANS[0] = 1, size = 0;
    for (int i = 0; i < idx; ++i) {
        while (power[i]--)mul(prime[i]);
    }
    for (int i = size; i >= 0; --i) printf("%d", ANS[i]);
}