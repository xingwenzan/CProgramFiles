//
// Created by 86159 on 2024-01-27.
// 满足条件的01序列 https://www.acwing.com/problem/content/891/
// ans = n 的卡特兰数 C_2n^n -C_2n^{n-1} = (C_2n^n)/(n+1)
// 解析 https://www.acwing.com/solution/content/8907/
//

#include "stdio.h"

typedef long long LL;
const int mod = 1e9 + 7;

int qmi(int a, int b, int p) {
    int ans = 1 % p;
    while (b) {
        if (b & 1)ans = (LL) ans * a % p;
        a = (LL) a * a % p;
        b >>= 1;
    }
    return ans;
}

int C(int a, int b, int p) {
    int x = 1 % p, y = 1 % p;
    for (int i = 1, j = a; i <= b; --j, ++i) {
        x = (LL) x * j % p;
        y = (LL) y * i % p;
    }
    return (LL) x * qmi(y, p - 2, p) % p;
}

int cattleya(int num) {
    // Cab 可以用符合数据范围的任何方法计算
    return (LL) C(2 * num, num, mod) * qmi(num + 1, mod - 2, mod) % mod;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", cattleya(n));
}