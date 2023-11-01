//
// Created by 86159 on 2023-10-28.
// 分解质因数 https://www.acwing.com/problem/content/869/
//

#include "stdio.h"

int n;

void count(int x) {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i)continue;
        int num = 0;
        while (x % i == 0) {
            x /= i;
            num++;
        }
        printf("%d %d\n", i, num);
    }
    if (x > 1)printf("%d 1\n", x);
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