//
// Created by 86159 on 2023-04-16.
// 左孩子右兄弟 https://www.acwing.com/problem/content/3425/
//

#include "stdio.h"
#define N 100010

int idx = 0,head[N],value[N],nextPointer[N];

void init(int n){
    for (int i = 0; i < n; ++i) {
        head[i] = -1;
    }
}

void add(int father,int son){
    value[idx] = son;
    nextPointer[idx] = head[father];
    head[father] = idx++;
}

int dfs(int root){
    int maxHeight=0,cnt=0;
    for (int i = head[root]; i !=-1;i = nextPointer[i]) {
        int tmp = dfs(value[i]);
        maxHeight = (maxHeight> tmp?maxHeight:tmp);
        cnt++;
    }
    return maxHeight+cnt;
}

int main(){
    int n,x;
    scanf("%d",&n);
    init(n+10);
    for (int i = 2; i <= n; ++i) {
        scanf("%d",&x);
        add(x,i);
    }
    printf("%d", dfs(1));
    return 0;
}