//
// Created by 86159 on 2023-11-01.
// 筛质数 https://www.acwing.com/problem/content/870/
// 朴素筛法/埃氏筛法
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
        if (st[i])continue;   // i 不是质数
        prime[cnt++] = i;
        for (int j = i + i; j <= n; j += i) {
            st[j] = true;
        }

    }
}

int main() {
    init();
    scanf("%d", &n);
    judge();
    printf("%d", cnt);
}