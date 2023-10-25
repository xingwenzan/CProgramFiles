//
// Created by 86159 on 2023-10-25.
// 试除法判定质数
//

#include "stdio.h"
#include "stdbool.h"

int n;

bool judge(int x) {
    if (x < 2)return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i)continue;
        return false;
    }
    return true;
}


int main() {
    scanf("%d", &n);
    int x;
    while (n--) {
        scanf("%d", &x);
        if (judge(x))puts("Yes");
        else puts("No");
    }
}