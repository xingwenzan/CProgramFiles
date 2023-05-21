//
// Created by 86159 on 2023-04-07.
// 截断数组 https://www.acwing.com/problem/content/3959/
//

#include "stdio.h"

#define N 100010

long lst[N], sum[N];

long prefixSum(int n) {
    if (n < 3) {
        return 0;
    }
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + lst[i - 1];
    }
    if (sum[n] % 3) {
        return 0;
    } else {
        long cnt = 0, ans = 0, s1 = sum[n] / 3, s2 = sum[n] / 3 * 2;
        for (int i = 2; i < n; ++i) {
            if (sum[i - 1] == s1) {
                cnt++;
            }
            if (sum[i] == s2) {
                ans += cnt;
            }
        }
        return ans;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &lst[i]);
    }
    printf("%ld\n", prefixSum(n));
    return 0;
}