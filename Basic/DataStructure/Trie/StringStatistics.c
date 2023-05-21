//
// Created by 86159 on 2023-05-21.
//

#include "stdio.h"

#define N 100010

int son[N][26], cnt[N], idx = 0;
char str[N];

void insert(char *string) {
    int pointer = 0;
    for (int i = 0; string[i]; ++i) {
        int letter = string[i] - 'a';
        if (!son[pointer][letter]) { son[pointer][letter] = ++idx; }
        pointer = son[pointer][letter];
    }
    cnt[pointer]++;
}

int query(char *string) {
    int pointer = 0;
    for (int i = 0; string[i]; ++i) {
        int letter = string[i] - 'a';
        if (!son[pointer][letter]) { return 0; }
        pointer = son[pointer][letter];
    }
    return cnt[pointer];
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}