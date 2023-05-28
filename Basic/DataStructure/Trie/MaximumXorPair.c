//
// Created by 86159 on 2023-05-28.
// 最大异或对 https://www.acwing.com/problem/content/145/
//

#include "stdio.h"

#define N 100010
#define P 3100010   // 最大节点个数   1e4 个数 * 31 位
int son[P][2], idx = 0, a[N];

void insert(int num) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        int x = (num >> i) & 1;
        if (!son[p][x]) { son[p][x] = ++idx; }
        p = son[p][x];
    }
}

int XOR(int num) {
    int ans = 0, p = 0;
    for (int i = 30; i >= 0; --i) {
        int x = (num >> i) & 1;
        if (son[p][!x]) {
            ans += 1 << i;
            p = son[p][!x];
        } else {
            p = son[p][x];
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = XOR(a[i]);
        ans = ans > tmp ? ans : tmp;
    }
    printf("%d", ans);
    return 0;
}