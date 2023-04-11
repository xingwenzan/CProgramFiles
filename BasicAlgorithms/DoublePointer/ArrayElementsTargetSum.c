//
// Created by 86159 on 2023-04-11.
// 数组元素的目标和 https://www.acwing.com/problem/content/802/
//
#include "stdio.h"
#define N 100010

int A[N],B[N];
int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&A[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d",&B[i]);
    }
    for (int i = 0,j=m-1; i < n; ++i) {
        while (j>=0 && A[i]+B[j]>x){
            j--;
        }
        if(j>=0 && A[i]+B[j]==x){
            printf("%d %d",i,j);
            break;
        }
    }
}