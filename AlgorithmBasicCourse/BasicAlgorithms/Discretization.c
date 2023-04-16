//
// Created by 86159 on 2023-04-14.
// 区间和 https://www.acwing.com/problem/content/804/
// 离散化本体: 排序 + 去重；查找: 二分；应用: 前缀和（本题）
//

#include "stdio.h"

#define N 300010
int point[N], length = 0, dedupPoint[N], dedupLength = 0, discretizedArray[N];

void quickSort(int l, int r) {
    if (l >= r) { return; }
    int i = l - 1, j = r + 1, x = point[(i + j) >> 1];
    while (i < j) {
        while (point[++i] < x) {}
        while (point[--j] > x) {}
        if(i<j){
            int tmp = point[i];
            point[i] = point[j];
            point[j] = tmp;
        }
    }
    quickSort(l, j);
    quickSort(j + 1, r);
}

void mergeSort(int l, int r) {
    if (l >= r) { return; }
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, tmp[r - l + 1], k = 0;
    while (i <= mid && j <= r) {
        if (point[i] <= point[j]) {
            tmp[k++] = point[i++];
        } else {
            tmp[k++] = point[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = point[i++];
    }
    while (j <= r) {
        tmp[k++] = point[j++];
    }
    for (int m = l, p = 0; m <= r; ++m, ++p) {
        point[m] = tmp[p];
    }
}

void discretization() {   // 离散化本体
    // 排序部分
    quickSort(0, length - 1);   // 375 ms
    mergeSort(0, length - 1);   // 406 ms
    // 去重部分
    dedupPoint[dedupLength++] = point[0];
    for (int i = 1; i < length; ++i) {
        if (point[i] != point[i - 1]) {
            dedupPoint[dedupLength++] = point[i];
        }
    }
}

int dichotomize(int num) {
    int l = 0, r = dedupLength - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (dedupPoint[mid] >= num) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void prefixSum() {
    for (int i = 1; i < dedupLength; ++i) {
        discretizedArray[i] += discretizedArray[i - 1];
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int xc[n][2], lr[m][2];
    int x, c, l, r;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &c);
        point[length++] = xc[i][0] = x;
        xc[i][1] = c;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &l, &r);
        point[length++] = lr[i][0] = l;
        point[length++] = lr[i][1] = r;
    }
    discretization();
    for (int i = 0; i < n; ++i) {
        x = dichotomize(xc[i][0]);
        discretizedArray[x] += xc[i][1];
    }
    prefixSum();
    for (int i = 0; i < m; ++i) {
        l = dichotomize(lr[i][0]);
        r = dichotomize(lr[i][1]);
        printf("%d\n", discretizedArray[r] - discretizedArray[l - 1]);
        // 注：此时可能存在 array[-1] 但该写法合法，不过指向内容未知，本题纯属侥幸，不推荐使用
    }
    return 0;
}