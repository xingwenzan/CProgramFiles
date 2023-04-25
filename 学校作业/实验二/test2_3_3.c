//
// Created by 86159 on 2023-04-25.
// 分别使用 for 语句以及 while 语句进行编程，要求编写程序实现 100 以内所有 素数的和 ，并粘贴 for 语句以及 while 语句的编程运行结果截图。
// 方法 3 : 线性筛
//

#include "stdio.h"
#include "stdbool.h"
#define N 100010

int prime[N],idx;   // 存质数; 记录质数个数
bool state[N];   // 记录是否不是质数，是 - 跳过，否 - 添加到 prime 里

int LinearSieve(int x){   // 取得到 x 的所有质数及其和
    idx = 0;
    if(x<=1){
        return 0;
    }
    int ans = 0;
    for (int i = 2; i <= x; ++i) {
        if(!state[i]){   // 是质数就记录
            ans += i;
            prime[idx++] = i;
        }
        for (int j = 0; prime[j] <= x/i; j++) {   // i * prime[j] <= x
            // 标记所有 i 与小于等于其最小质因数的所有质数的积
            // 如此可保证所有合数只枚举一次
            // 如 12 在埃氏筛中被 2 3 各枚举一次，在此只会被 6 筛一次
            state[i*prime[j]] = true;
            if(i%prime[j]==0){ break;}
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
    printf("总和为:\n%d\n这些数分别是:\n", LinearSieve(n));
    getPrime();
    printf("\n20212703411 张馨文");
    return 0;
}