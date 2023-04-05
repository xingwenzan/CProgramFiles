//
// Created by 86159 on 2023-04-04.
// 编写程序，任意输入 4 个自然数，求和并输出。要求写出程序语句，并粘贴运行结果截图。
//
#include "stdio.h"
#include "string.h"

#define N 100010

int ans[N], length;

void add(char num[]) {
    // 新进来的数重新储存
    int lenX = strlen(num), x[N], tmp[N];
    for (int i = 0, j = lenX - 1; i < lenX; ++i, --j) {
        x[j] = num[i] - '0';
    }
    // ans 赋值给 tmp，ans 存结果
    for (int i = 0; i < length; ++i) {
        tmp[i] = ans[i];
    }
    int i, t = 0;
    // 简单的加法，按位相加，过十进位
    for (i = 0; i < length || i < lenX; i++) {
        if (i < lenX) { t += x[i]; }
        if (i < length) { t += tmp[i]; }
        ans[i] = t % 10;
        t /= 10;
    }
    // 可能还剩一位，放进去就 OK
    if (t > 0) {
        ans[i] = t;
        length = i + 1;
    } else{
        length = i;
    }
}

int main() {
    // long 数据范围 [2^31,2^31-1]，上限大概比 2*(10^9) 大一点
    printf("请问是否为大数据运算（预计结果绝对值可能超过 1e9）\n");
    printf("是(请键入 'y')\n否(请键入 'n')\n");
    char mode;
    scanf("%c", &mode);
    printf("请输入相加的 4 个数，用空格或回车分隔\n");
    if (mode == 'n') {
        long a, b, c, d;
        scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
        printf("%ld\n", a + b + c + d);
    } else {
        char num[N];
        // 读入第一个数据,并以此为结果，每次循环都是直接在其身上改变，经过下面 3 次循环以后就是需要的答案
        // 4 个数及其结果在都储存在数组里，且随着标号的增大，储存位数随着增大，方便计算
        // （0 号位 - 个位，1 号位 - 十位，2 号位 - 百位，以此类推）
        // 但由于计算后无法确定数字位数，不好输出，且计算过程需要知道位数，故需要一个 length 辅助
        scanf("%s", &num);
        length = strlen(num);
        for (int i = 0, j = length - 1; i < length; ++i, --j) {
            ans[j] = num[i] - '0';
        }
        // 循环读入第 2~4 个数据，并加到 ans 上
        // 这个就不用搁外面直接转了，扔 add 函数里面也好看一点
        for (int i = 0; i < 3; ++i) {
            char num[N];
            scanf("%s", &num);
            add(num);
        }
        for (int i = length - 1; i >= 0; --i) {
            if(i%3==2){   // 为了好看，加上千分位符
                printf(",");
            }
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    printf("20212703411 张馨文");
    return 0;
}