//
// Created by 86159 on 2023-04-09.
// 改变数组元素 https://www.acwing.com/problem/content/3732/
//

#include <strings.h>
#include "stdio.h"
#define N 200010
int lst[N], n, T, x;

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &n);
        memset(lst,0,(n+1)* sizeof(int));
        for (int j = 0; j < n; ++j) {
            scanf("%d", &x);
            int l, r;
            l = (j - x + 1 >= 0) ? j - x + 1 : 0;
            r = j + 1;
            lst[l]++;
            lst[r]--;
        }
        for (int j = 1; j <= n; ++j) {
            lst[j] += lst[j - 1];
            printf("%d ", !!lst[j - 1]);
        }
        printf("\n");
    }
}