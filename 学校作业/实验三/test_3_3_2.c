//
// Created by 86159 on 2023-05-29.
// ���õ����ⲿ�����ķ������� 1!+2!+��+10!�Ľ������ճ�� for ����Լ� while ���ı�����н����ͼ��
//

#include "stdio.h"

// ��׳˺���
int factorial(int n) {
    int ans = 1;
    while (n) {
        ans *= n;
        n--;
    }
    return ans;
}

// �׳����
int factorialSum(int n) {
    int ans = 0;
    while (n){
        ans += factorial(n);
        n--;
    }
    return ans;
}

int main() {
    printf("�� n �Ľ׳˵ĺ�\n");
    int n;
    scanf("%d",&n);
    factorialSum(n);
    printf("%d",factorialSum(n));
    printf("\n20212703411 ��ܰ��\n");
}