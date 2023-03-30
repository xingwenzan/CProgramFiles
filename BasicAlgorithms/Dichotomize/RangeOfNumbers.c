//
// Created by 86159 on 2023-03-29.
// 数的范围 https://www.acwing.com/problem/content/791/
//
#include "stdio.h"

#define N 100010

int lst[N];

int dichotomizeMax(int num, int lenght) {
    int l = 0, r = lenght - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (lst[mid] <= num) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    if (lst[l] == num) {
        return r;
    } else {
        return -1;
    }
}

int dichotomizeMin(int num, int lenght) {
    int l = 0, r = lenght - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (lst[mid] >= num) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (lst[r] == num) {
        return l;
    } else {
        return -1;
    }
}

int main() {
    int n, q, x;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &lst[i]);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d", &x);
        printf("%d %d\n", dichotomizeMin(x, n), dichotomizeMax(x, n));
    }

    return 0;
}