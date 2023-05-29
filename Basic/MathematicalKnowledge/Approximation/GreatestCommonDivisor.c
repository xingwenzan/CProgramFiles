//
// Created by 86159 on 2023-05-29.
// 最大公约数 https://www.acwing.com/problem/content/874/
//

#include "stdio.h"

int gcd(int a,int b){
    return b!=0?gcd(b,a%b):a;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n", gcd(a,b));
    }

    printf("\n20212703411 张馨文\n");
}