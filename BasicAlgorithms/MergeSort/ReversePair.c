//
// Created by 86159 on 2023-03-28.
// 逆序对的数量 https://www.acwing.com/problem/content/790/
//

#include "stdio.h"

#define N 100010

typedef long long LL;

int q[N], n;

LL reversePair(int l, int r) {
    if (l >= r) { return 0; }
    int mid = (l + r) >> 1, i = l, j = mid + 1, k = 0, tmp[r - l + 1];
    LL ans = reversePair(l, mid) + reversePair(mid + 1, r);
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        } else {
            tmp[k++] = q[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    while (j <= r) {
        tmp[k++] = q[j++];
    }
    for (int m = l, p = 0; m <= r; ++m, ++p) {
        q[m] = tmp[p];
    }

    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }
    printf("%lld", reversePair(0, n - 1));
    return 0;
}