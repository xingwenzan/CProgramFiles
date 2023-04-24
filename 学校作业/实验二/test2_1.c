//
// Created by 86159 on 2023-04-24.
//
#include <stdbool.h>
#include "stdio.h"
#include "string.h"

#define N 100000
char ch[N];

bool isDecimal(){   // �ж�С��
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
    // �ж�С��
    if(isDecimal()){
        printf("С��\n����ż��\n�Ȳ���������Ҳ���Ǻ���\n");
    } else{
        printf("����\n");
        int tmp = 0;
        for (int i = 0; i < strlen(ch); ++i) {
            tmp = tmp*10+(ch[i]-'0');
        }
        // �ж���ż��
        if(tmp%2){
            printf("����\n");
        } else{
            printf("ż��\n");
        }
        // �ж�����
        int prime = isPrime(tmp);
        if(prime==2){
            printf("����\n");
        } else if(prime==1){
            printf("����\n");
        } else{
            printf("�Ȳ���������Ҳ���Ǻ���\n");
        }
    }
    printf("20212703411 ��ܰ��");
}