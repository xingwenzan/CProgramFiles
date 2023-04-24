//
// Created by 86159 on 2023-04-24.
//
#include <stdbool.h>
#include "stdio.h"
#include "string.h"

#define N 100000
char ch[N];

bool isDecimal(){   // 判断小数
    for (int i = 0; i < strlen(ch); ++i) {
        if(ch[i]=='.'){
            return true;
        }
    }
    return false;
}

int isPrime(int x){
    if(x<=1){
        return 0;
    }
    for (int i = 2; i <= x / i; ++i) {
        if(x%i==0){
            return 1;
        }
    }
    return 2;
}

int main(){
    scanf("%s",ch);
    // 判断小数
    if(isDecimal()){
        printf("小数\n无奇偶性\n既不是素数，也不是合数\n");
    } else{
        printf("整数\n");
        int tmp = 0;
        for (int i = 0; i < strlen(ch); ++i) {
            tmp = tmp*10+(ch[i]-'0');
        }
        // 判断奇偶性
        if(tmp%2){
            printf("奇数\n");
        } else{
            printf("偶数\n");
        }
        // 判断宿舍
        int prime = isPrime(tmp);
        if(prime==2){
            printf("素数\n");
        } else if(prime==1){
            printf("合数\n");
        } else{
            printf("既不是素数，也不是合数\n");
        }
    }
    printf("20212703411 张馨文");
}