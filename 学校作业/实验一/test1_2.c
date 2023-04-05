//
// Created by 86159 on 2023-04-05.
// 编写程序，两个自然数相除，取余数。要求写出程序语句，并粘贴运行结果截图
//
#include "stdio.h"
#include "string.h"

#define N 100010

int quotient[N];   // 对本题没什么用，用来存商的

int mod(char dividend[], int divisor) {
    int length = strlen(dividend), tmp = 0;
    // 小学除法
    for (int i = 0; i < length; ++i) {
        tmp = tmp * 10 + (dividend[i] - '0');
        quotient[i] = tmp / divisor;
        tmp %= divisor;
    }
    return tmp;
}

int main() {
    printf("请问是否为大数据运算（预计结果绝对值可能超过 1e9）\n");
    printf("是(请键入 'y')\n否(请键入 'n')\n");
    char mode;
    scanf("%c", &mode);
    if (mode == 'n') {
        long a, b;
        printf("请输入被除数：");
        scanf("%ld", &a);
        printf("请输入除数：");
        scanf("%ld", &b);
        printf("%ld\n", a % b);
    } else {
        char a[N];
        int b;
        printf("请输入被除数：");
        scanf("%s", &a);
        printf("请输入除数：");
        scanf("%d", &b);
        int remainder = mod(a, b);
        printf("商：");
        int i;
        for (i = 0; i < strlen(a); ++i) {
            if (quotient[i]) {
                break;
            }
        }
        for (; i < strlen(a); ++i) {
            printf("%d",quotient[i]);
            // 添加千分位符
            if((strlen(a)-i)%3==1 && strlen(a)-i>1){
                printf(",");
            }
        }
        printf("\n余数：%d\n", remainder);
    }
    printf("20212703411 张馨文");
    return 0;
}