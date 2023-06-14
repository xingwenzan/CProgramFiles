//
// Created by 86159 on 2023-06-14.
// 模拟散列表 https://www.acwing.com/problem/content/842/
// 开放寻址法
//

#include "stdio.h"
#define N 200003
#define null 0x3f3f3f
int hash[N];

int find(int x){
    int p = (x%N+N)%N;
    while (hash[p]!=x && hash[p]!=null){
        p++;
        if (p==N){p=0;}
    }
    return p;
}

void insert(int x){
    hash[find(x)] = x;
}

int exist(int x){
    int p = find(x);
    if (hash[p]==x){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    for (int i = 0; i < N; ++i) {
        hash[i] = null;
    }
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        char op;
        int x;
        scanf("\n%c%d",&op,&x);
        if (op=='I'){
            insert(x);
        } else{
            if (exist(x)){
                printf("Yes\n");
            } else{
                printf("No\n");
            }
        }
    }
}