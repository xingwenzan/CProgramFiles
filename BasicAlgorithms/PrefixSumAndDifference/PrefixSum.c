//
// Created by 86159 on 2023-04-01.
// 前缀和 https://www.acwing.com/problem/content/797/
//

#include "stdio.h"

#define N 100010

int nums[N];

int *prefixSum(int lst[], int lenght) {
    static int ans[N];
    ans[0] = 0;
    for (int i = 1; i <= lenght; ++i) {
        ans[i] = ans[i - 1] + lst[i - 1];
    }
    return ans;
}

int main() {
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    int *sumNums = prefixSum(nums, n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &l, &r);
        printf("%d\n", *(sumNums + r) - *(sumNums + (l - 1)));
    }
    return 0;
}