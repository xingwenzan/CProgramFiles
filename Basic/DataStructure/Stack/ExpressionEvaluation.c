//
// Created by 86159 on 2023-04-22.
// 表达式求值 https://www.acwing.com/problem/content/3305/
//

#include "stdio.h"
#include "string.h"
#include "ctype.h"
#define N 100010

char expression[N],sign[N];
int num[N],idxN = 0,idxS = 0;

int hash(char ch){
    if(ch=='('){
        return 0;
    } else if(ch=='+' || ch=='-'){
        return 1;
    } else if(ch=='*' || ch=='/'){
        return 2;
    } else{
        return N;
    }
}

void eval(){
    int a = num[--idxN],b = num[--idxN];
    char c = sign[--idxS];
    if(c=='+'){
        num[idxN++] = a+b;
    } else if(c=='-'){
        num[idxN++] = b-a;
    } else if(c=='*'){
        num[idxN++] = b*a;
    } else{
        num[idxN++] = (int )(b/a);
    }
}

int main(){
    scanf("%s",expression);
    int n = strlen(expression);
    for (int i = 0; i < n; ++i) {
        char c = expression[i];
        if(isdigit(c)){
            int x = c-'0',j=i+1;
            while (isdigit(expression[j])){
                x = x*10+(expression[j++]-'0');
            }
            num[idxN++] = x;
            i = j-1;
        } else if(c=='('){
            sign[idxS++] = c;
        } else if(c==')'){
            while (sign[idxS-1]!='('){
                eval();
            }
            idxS--;
        } else{
            while (idxS>=1 && hash(c)<= hash(sign[idxS-1])){
                eval();
            }
            sign[idxS++] = c;
        }
    }
    while (idxS!=0){
        eval();
    }
    printf("%d",num[0]);
    return 0;
}