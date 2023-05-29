//
// Created by 86159 on 2023-05-29.
// ���������д����������� 0-200 ��������Ҫ��д��������䣬��ճ�����н����ͼ
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
    printf("���������������ķ�Χ��\n");
    int st,ed;
    scanf("%d%d",&st,&ed);
    // for д��
    printf("\nfor д����\n");
    for (int i = st; i <= ed; ++i) {
        if(isPrime(i)){
            printf("%d ",i);
        }
    }
    // while д��
    int i = st;
    printf("\nwhile д����\n");
    while (i<=ed && i>= st){
        if(isPrime(i)){
            printf("%d ",i);
        }
        i++;
    }
    printf("\n20212703411 ��ܰ��\n");
    return 0;
}