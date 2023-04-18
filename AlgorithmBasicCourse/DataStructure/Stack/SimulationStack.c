//
// Created by 86159 on 2023-04-18.
// 模拟栈 https://www.acwing.com/problem/content/830/
//

#include <stdbool.h>
#include "stdio.h"
#include "string.h"
#define M 100010

int stack[M],idx=-1;

void push(int num){
    stack[++idx] = num;
}

void pop(){
    idx--;
}

bool empty(){
    return idx==-1;
}

int query(){
    return stack[idx];
}

int main(){
    int n,x;
    char op[10];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",op);
        if(!strcmp(op,"push")){
            scanf("%d",&x);
            push(x);
        } else if(!strcmp(op,"pop")){
            pop();
        } else if(!strcmp(op,"empty")){
            empty()? printf("YES"): printf("NO");
            printf("\n");
        } else{
            printf("%d\n",query());
        }
    }

    return 0;
}