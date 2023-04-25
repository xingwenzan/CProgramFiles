//
// Created by 86159 on 2023-04-25.
// �ֱ�ʹ�� for ����Լ� while �����б�̣�Ҫ���д����ʵ�� 100 �������� �����ĺ� ����ճ�� for ����Լ� while ���ı�����н����ͼ��
// ���� 3 : ����ɸ
//

#include "stdio.h"
#include "stdbool.h"
#define N 100010

int prime[N],idx;   // ������; ��¼��������
bool state[N];   // ��¼�Ƿ����������� - �������� - ��ӵ� prime ��

int LinearSieve(int x){   // ȡ�õ� x ���������������
    idx = 0;
    if(x<=1){
        return 0;
    }
    int ans = 0;
    for (int i = 2; i <= x; ++i) {
        if(!state[i]){   // �������ͼ�¼
            ans += i;
            prime[idx++] = i;
        }
        for (int j = 0; prime[j] <= x/i; j++) {   // i * prime[j] <= x
            // ������� i ��С�ڵ�������С�����������������Ļ�
            // ��˿ɱ�֤���к���ֻö��һ��
            // �� 12 �ڰ���ɸ�б� 2 3 ��ö��һ�Σ��ڴ�ֻ�ᱻ 6 ɸһ��
            state[i*prime[j]] = true;
            if(i%prime[j]==0){ break;}
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
    printf("�ܺ�Ϊ:\n%d\n��Щ���ֱ���:\n", LinearSieve(n));
    getPrime();
    printf("\n20212703411 ��ܰ��");
    return 0;
}