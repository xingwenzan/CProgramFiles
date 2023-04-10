//
// Created by 86159 on 2023-04-10.
// 最长连续不重复子序列 https://www.acwing.com/problem/content/801/
//
#include "stdio.h"
#define max(i,j) (((i) > (j)) ? (i) : (j))
#define N 100010

int q[N],state[N];

int main(){
    int n,ans=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&q[i]);
    }
    for (int i = 0,j=0; i < n; ++i) {
        state[q[i]]++;
        while (j<i && state[q[i]]>1){state[q[j++]]--;}
        ans = max(ans,i-j+1);
    }
    printf("%d",ans);
}