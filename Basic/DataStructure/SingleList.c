//
// Created by 86159 on 2023-04-16.
// 单链表 https://www.acwing.com/problem/content/828/
//

#include "stdio.h"

#define M  100010

int pointerArray[M], valueArray[M], idx = 1;

void add(int pointer, int value) {
    valueArray[idx] = value;
    pointerArray[idx] = pointerArray[pointer];
    pointerArray[pointer] = idx++;
}

void delete(int pointer) {
    pointerArray[pointer] = pointerArray[pointerArray[pointer]];
}

int main() {
    pointerArray[0] = -1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char op;
        int p,e;
        scanf("\n%c", &op);   // \n 吃掉换行符

        if (op == 'H') {
            scanf("%d", &e);
            add(0, e);
        } else if (op == 'D') {
            scanf("%d", &p);
            delete(p);
        } else {
            scanf("%d%d", &p, &e);
            add(p, e);
        }
    }
    for (int i = pointerArray[0]; i != -1; i = pointerArray[i]) {
        printf("%d ", valueArray[i]);
    }
    return 0;
}