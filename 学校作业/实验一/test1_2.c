//
// Created by 86159 on 2023-04-05.
// ��д����������Ȼ�������ȡ������Ҫ��д��������䣬��ճ�����н����ͼ
//
#include "stdio.h"
#include "string.h"

#define N 100010

int quotient[N];   // �Ա���ûʲô�ã��������̵�

int mod(char dividend[], int divisor) {
    int length = strlen(dividend), tmp = 0;
    // Сѧ����
    for (int i = 0; i < length; ++i) {
        tmp = tmp * 10 + (dividend[i] - '0');
        quotient[i] = tmp / divisor;
        tmp %= divisor;
    }
    return tmp;
}

int main() {
    printf("�����Ƿ�Ϊ���������㣨Ԥ�ƽ������ֵ���ܳ��� 1e9��\n");
    printf("��(����� 'y')\n��(����� 'n')\n");
    char mode;
    scanf("%c", &mode);
    if (mode == 'n') {
        long a, b;
        printf("�����뱻������");
        scanf("%ld", &a);
        printf("�����������");
        scanf("%ld", &b);
        printf("%ld\n", a % b);
    } else {
        char a[N];
        int b;
        printf("�����뱻������");
        scanf("%s", &a);
        printf("�����������");
        scanf("%d", &b);
        int remainder = mod(a, b);
        printf("�̣�");
        int i;
        for (i = 0; i < strlen(a); ++i) {
            if (quotient[i]) {
                break;
            }
        }
        for (; i < strlen(a); ++i) {
            printf("%d",quotient[i]);
            // ���ǧ��λ��
            if((strlen(a)-i)%3==1 && strlen(a)-i>1){
                printf(",");
            }
        }
        printf("\n������%d\n", remainder);
    }
    printf("20212703411 ��ܰ��");
    return 0;
}