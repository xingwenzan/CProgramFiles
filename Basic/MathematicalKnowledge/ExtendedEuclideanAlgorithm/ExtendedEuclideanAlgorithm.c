//
// Created by 86159 on 2023-12-03.
// 扩展欧几里得算法 https://www.acwing.com/problem/content/879/
// *x *y 代表传入参数应为 x y 的地址，即 &x &y
// *x *y 为真实的 x y 值
// https://www.cnblogs.com/yanlingyin/archive/2011/12/07/2278961.html
//

#include "stdio.h"

int n;

int gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1, *y = 0;
        return a;
    }
    int d = gcd(b, a % b, y, x);
    *y -= a / b * (*x);
    return d;
}

int main() {
    scanf("%d", &n);
    int a, b, x, y;
    while (n--) {
        scanf("%d%d", &a, &b);
        x = 0, y = 0;
        int d = gcd(a, b, &x, &y);
        printf("%d %d\n", x, y);
    }
}