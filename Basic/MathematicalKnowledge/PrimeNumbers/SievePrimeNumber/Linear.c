//
// Created by 86159 on 2023-11-01.
// 筛质数 https://www.acwing.com/problem/content/870/
// 线性筛法
//

#include "stdio.h"
#include "stdbool.h"

#define N 1000010

int n;
int prime[N], cnt = 0;   // 记录质数及数量
bool st[N];    // 谁不是质数，true 不是质数，false 是质数

void init() {
    for (int i = 0; i < N; ++i) {
        st[i] = false;
    }
    st[0] = st[1] = true;
}

void judge() {
    if (n < 2)return;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; prime[j] <= n / i; ++j) {
            st[i * prime[j]] = true;
            if (i % prime[j] == 0)break;
        }
    }
}

int main() {
    init();
    scanf("%d", &n);
    judge();
    printf("%d", cnt);
    return 0;
}