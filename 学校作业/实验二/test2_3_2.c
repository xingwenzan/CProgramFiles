//
// Created by 86159 on 2023-04-25.
// �ֱ�ʹ�� for ����Լ� while �����б�̣�Ҫ���д����ʵ�� 100 �������� �����ĺ� ����ճ�� for ����Լ� while ���ı�����н����ͼ��
// ���� 2 : ����ɸ
//

#include "stdio.h"
#include "stdbool.h"
#define N 100010

int prime[N],idx;   // ������; ��¼������������Ȼ�����������������п��ޣ�
bool state[N];   // ��¼�Ƿ����������� - �������� - ��ӵ� prime ��

int EssiereSieve(int x){   // ȡ�õ� x ���������������
    idx = 0;
    if(x<=1){
        return 0;
    }
    int ans = 0;
    for (int i = 2; i <= x; ++i) {
        if(state[i]){   // ��������������
            continue;
        }
        ans += i;
        prime[idx++] = i;
        for (int j = i+i; j <= x; j+=i) {   // i �����б�������������
            state[j] = true;
        }
    }
    return ans;
}

void getPrime(){
    if(!idx){
        printf("û������");
    }
    for (int i = 0; i < idx; ++i) {
        printf("%d ",prime[i]);
    }
}

int main(){
    int n;
    printf("��������Ҫ�������ڵ�����:\n");
    scanf("%d",&n);
    printf("�ܺ�Ϊ:\n%d\n��Щ���ֱ���:\n", EssiereSieve(n));
    getPrime();
    printf("\n20212703411 ��ܰ��");
    return 0;
}