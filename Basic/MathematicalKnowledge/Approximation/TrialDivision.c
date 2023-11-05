//
// Created by 86159 on 2023-11-05.
// 试除法求约数
//

#include "stdio.h"

#define N 100010

int n;
int l[N], r[N], l_idx, r_idx;

void count(int x) {
    l_idx = r_idx = 0;
    for (int i = 1; i <= x / i; ++i) {
        if (x % i)continue;
        l[l_idx++] = i;
        if (i < x / i)r[r_idx++] = x / i;
    }
    for (int i = 0; i < l_idx; ++i) {
        printf("%d ", l[i]);
    }
    for (int i = r_idx - 1; i >= 0; --i) {
        printf("%d ", r[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);
    int x;
    while (n--) {
        scanf("%d", &x);
        count(x);
    }
}