//
// Created by 86159 on 2023-04-25.
// 分别使用 for 语句以及 while 语句进行编程，要求编写程序实现 100 以内所有 素数的和 ，并粘贴 for 语句以及 while 语句的编程运行结果截图。
// 方法 1: 朴素算法(暴力法), 循环, 一个一个带入判定素数方法
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
    int sum1 = 0;
    // for 写法
    for (int i = 0; i <= 100; ++i) {
        if(isPrime(i)){
            sum1+=i;
        }
    }
    // while 写法
    int i = 0,sum2 = 0;
    while (i<=100){
        if(isPrime(i)){
            sum2+=i;
        }
        i++;
    }
    printf("%d\n", sum1);
    printf("%d\n", sum2);
    printf("20212703411 张馨文");
    return 0;
}