//
// Created by 86159 on 2023-05-14.
// KMP字符串 https://www.acwing.com/problem/content/833/
// 视频解析 https://www.acwing.com/video/259/
// 文字解析 https://www.acwing.com/solution/content/129372/
// next[i] 表示使字串 s[0…i] 中前缀 s[0…k] 等于后缀 s[i-k…i] 的最大的 k
// next[i] 就是使子串 s[0…i] 有最长相等前后缀的前缀的最后一位的下标
//

#include "stdio.h"

#define N 100010
#define M 1000010

char p[N], s[M];
int ne[N];

int main() {
    int n, m;
    scanf("%d%s%d%s", &n, p + 1, &m, s + 1);   // 字符串下标从 1 开始
    for (int i = 2, j = 0; i <= n; ++i) {   // 不能记录自己和自己比较情况，故从 2 开始
        while (j && p[i] != p[j + 1]) { j = ne[j]; }   //  往前翻 减少前缀后缀长度比较
        if (p[i] == p[j + 1]) { j++; }
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; ++i) {   // 与长字符串匹配从0开始
        while (j && s[i] != p[j + 1]) { j = ne[j]; }
        if (s[i] == p[j + 1]) { j++; }
        if (j == n) {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
    return 0;
}