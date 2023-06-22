//
// Created by 86159 on 2023-06-22.
// 字符串哈希 https://www.acwing.com/problem/content/843/
// 字符串前缀哈希法
// 假定人品够好，没有冲突（一般取 131或13331进制，用 2**64 取模）
//

#include "stdio.h"

#define N 100010   // 字符串最大长度，受给出题目数据范围限制
#define P 131   // P 进制，类比十进制、二进制的 10、2
typedef unsigned long long ULL;
char str[N];   // 原字符串
ULL h[N], p[N];   // 字符串前缀数组，h[i] 即前 i 位字符串代替数字   进制数组，p[i] 即 p^i

void init(int length) {
    p[0] = 1;
    for (int i = 1; i <= length; ++i) {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
}

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);   // 从 1 号位开始放
    init(n);
    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}