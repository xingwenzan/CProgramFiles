//
// Created by 86159 on 2023-04-11.
// 判断子序列 https://www.acwing.com/problem/content/2818/
//

#include "stdio.h"

#define N 100010

int a[N], b[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) { i++; }
        j++;
    }
    if (i == n) { printf("Yes"); }
    else { printf("No"); }
}