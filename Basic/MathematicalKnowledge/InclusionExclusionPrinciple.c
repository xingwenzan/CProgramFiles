//
// Created by 86159 on 2024-01-30.
// 容斥原理 能被整除的数 https://www.acwing.com/problem/content/892/
// 解析 https://www.acwing.com/solution/content/17517/
//
#include "stdio.h"

#define N 20
typedef long long LL;
int p[N];

int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d", &p[i]);

    for (int i = 1; i < (1 << m); ++i) {
        int t = 1, s = 0;   // t: s 个 pi 的乘积; s: 相乘 pi 的个数，根据其奇偶性判断加减

        for (int j = 0; j < m; ++j) {
            if (i >> j & 1) {
                if ((LL) t * p[j] > n) {
                    t = -1;
                    break;
                }
                t *= p[j];
                s++;
            }
        }

        if (t != -1) {
            if (s % 2)ans += n / t;
            else ans -= n / t;
        }
    }

    printf("%d", ans);
    return 0;
}