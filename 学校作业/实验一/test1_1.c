//
// Created by 86159 on 2023-04-04.
// ��д������������ 4 ����Ȼ������Ͳ������Ҫ��д��������䣬��ճ�����н����ͼ��
//
#include "stdio.h"
#include "string.h"

#define N 100010

int ans[N], length;

void add(char num[]) {
    // �½����������´���
    int lenX = strlen(num), x[N], tmp[N];
    for (int i = 0, j = lenX - 1; i < lenX; ++i, --j) {
        x[j] = num[i] - '0';
    }
    // ans ��ֵ�� tmp��ans ����
    for (int i = 0; i < length; ++i) {
        tmp[i] = ans[i];
    }
    int i, t = 0;
    // �򵥵ļӷ�����λ��ӣ���ʮ��λ
    for (i = 0; i < length || i < lenX; i++) {
        if (i < lenX) { t += x[i]; }
        if (i < length) { t += tmp[i]; }
        ans[i] = t % 10;
        t /= 10;
    }
    // ���ܻ�ʣһλ���Ž�ȥ�� OK
    if (t > 0) {
        ans[i] = t;
        length = i + 1;
    } else{
        length = i;
    }
}

int main() {
    // long ���ݷ�Χ [2^31,2^31-1]�����޴�ű� 2*(10^9) ��һ��
    printf("�����Ƿ�Ϊ���������㣨Ԥ�ƽ������ֵ���ܳ��� 1e9��\n");
    printf("��(����� 'y')\n��(����� 'n')\n");
    char mode;
    scanf("%c", &mode);
    printf("��������ӵ� 4 �������ÿո��س��ָ�\n");
    if (mode == 'n') {
        long a, b, c, d;
        scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
        printf("%ld\n", a + b + c + d);
    } else {
        char num[N];
        // �����һ������,���Դ�Ϊ�����ÿ��ѭ������ֱ���������ϸı䣬�������� 3 ��ѭ���Ժ������Ҫ�Ĵ�
        // 4 �����������ڶ�����������������ű�ŵ����󣬴���λ���������󣬷������
        // ��0 ��λ - ��λ��1 ��λ - ʮλ��2 ��λ - ��λ���Դ����ƣ�
        // �����ڼ�����޷�ȷ������λ��������������Ҽ��������Ҫ֪��λ��������Ҫһ�� length ����
        scanf("%s", &num);
        length = strlen(num);
        for (int i = 0, j = length - 1; i < length; ++i, --j) {
            ans[j] = num[i] - '0';
        }
        // ѭ������� 2~4 �����ݣ����ӵ� ans ��
        // ����Ͳ��ø�����ֱ��ת�ˣ��� add ��������Ҳ�ÿ�һ��
        for (int i = 0; i < 3; ++i) {
            char num[N];
            scanf("%s", &num);
            add(num);
        }
        for (int i = length - 1; i >= 0; --i) {
            if(i%3==2){   // Ϊ�˺ÿ�������ǧ��λ��
                printf(",");
            }
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    printf("20212703411 ��ܰ��");
    return 0;
}