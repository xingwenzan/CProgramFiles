//
// Created by 86159 on 2023-05-29.
// 利用调用外部函数的方法，求 1!+2!+…+10!的结果，并粘贴 for 语句以及 while 语句的编程运行结果截图。
//

#include "stdio.h"

// 求阶乘函数
int factorial(int n) {
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

// 阶乘相加
int factorialSum(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += factorial(i);
    }
    return ans;
}

int main() {
    printf("求到 n 的阶乘的和\n");
    int n;
    scanf("%d",&n);
    printf("%d",factorialSum(n));
    printf("\n20212703411 张馨文\n");
}