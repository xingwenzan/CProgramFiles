//
// Created by 86159 on 2023-11-19.
// 欧拉函数 https://www.acwing.com/problem/content/875/
//

#include "stdio.h"

int n;

int euler(int x) {
    int ans = x;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i)continue;
        ans = ans / i * (i - 1);
        while (x % i == 0) {
            x /= i;
        }
    }

    if (x > 1)ans = ans / x * (x - 1);
    return ans;
}

int main() {
    scanf("%d", &n);
    int x;
    while (n--) {
        scanf("%d", &x);
        printf("%d\n", euler(x));
    }
}