//
// Created by 86159 on 2023-03-30.
// 数的三次方根 https://www.acwing.com/problem/content/792/
//

#include "stdio.h"
#include "math.h"

double dichotomize(double x) {
    double l = -100, r = 100;
    while (r - l > pow(10, -8)) {
        double mid = (l + r) / 2;
        if (pow(mid, 3) <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    double n;
    scanf("%lf", &n);
    printf("%.6lf", dichotomize(n));
    return 0;
}