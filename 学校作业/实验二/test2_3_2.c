//
// Created by 86159 on 2023-04-25.
// 分别使用 for 语句以及 while 语句进行编程，要求编写程序实现 100 以内所有 素数的和 ，并粘贴 for 语句以及 while 语句的编程运行结果截图。
// 方法 2 : 埃氏筛
//

#include "stdio.h"
#include "stdbool.h"
#define N 100010

int prime[N],idx;   // 存质数; 记录质数个数（当然，本题中这两个可有可无）
bool state[N];   // 记录是否不是质数，是 - 跳过，否 - 添加到 prime 里

int EssiereSieve(int x){   // 取得到 x 的所有质数及其和
    idx = 0;
    if(x<=1){
        return 0;
    }
    int ans = 0;
    for (int i = 2; i <= x; ++i) {
        if(state[i]){   // 不是质数就跳过
            continue;
        }
        ans += i;
        prime[idx++] = i;
        for (int j = i+i; j <= x; j+=i) {   // i 的所有倍数都不是质数
            state[j] = true;
        }
    }
    return ans;
}

void getPrime(){
    if(!idx){
        printf("没有素数");
    }
    for (int i = 0; i < idx; ++i) {
        printf("%d ",prime[i]);
    }
}

int main(){
    int n;
    printf("请问您想要多少以内的素数:\n");
    scanf("%d",&n);
    printf("总和为:\n%d\n这些数分别是:\n", EssiereSieve(n));
    getPrime();
    printf("\n20212703411 张馨文");
    return 0;
}