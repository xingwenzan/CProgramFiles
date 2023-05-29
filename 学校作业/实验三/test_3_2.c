//
// Created by 86159 on 2023-05-29.
// 利用数组编写程序，输出所有 0-200 的素数。要求写出程序语句，并粘贴运行结果截图
//

#include <stdbool.h>
#include "stdio.h"

bool isPrime(int x){
    if(x<=1){
        return false;
    }
    for (int i = 2; i <= x / i; ++i) {
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    printf("请输入求找素数的范围：\n");
    int st,ed;
    scanf("%d%d",&st,&ed);
    // for 写法
    printf("\nfor 写法：\n");
    for (int i = st; i <= ed; ++i) {
        if(isPrime(i)){
            printf("%d ",i);
        }
    }
    // while 写法
    int i = st;
    printf("\nwhile 写法：\n");
    while (i<=ed && i>= st){
        if(isPrime(i)){
            printf("%d ",i);
        }
        i++;
    }
    printf("\n20212703411 张馨文\n");
    return 0;
}