//
// Created by 86159 on 2023-04-25.
// �ֱ�ʹ�� for ����Լ� while �����б�̣�Ҫ���д����ʵ�� 100 �������� �����ĺ� ����ճ�� for ����Լ� while ���ı�����н����ͼ��
// ���� 1: �����㷨(������), ѭ��, һ��һ�������ж���������
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
    int sum1 = 0;
    // for д��
    for (int i = 0; i <= 100; ++i) {
        if(isPrime(i)){
            sum1+=i;
        }
    }
    // while д��
    int i = 0,sum2 = 0;
    while (i<=100){
        if(isPrime(i)){
            sum2+=i;
        }
        i++;
    }
    printf("%d\n", sum1);
    printf("%d\n", sum2);
    printf("20212703411 ��ܰ��");
    return 0;
}