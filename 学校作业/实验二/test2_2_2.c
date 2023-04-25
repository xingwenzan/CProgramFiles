#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int start, int end) {
    if (start == end) {
        printf("%d %d %d\n", arr[0], arr[1], arr[2]);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);
        permute(arr, start + 1, end);
        swap(&arr[start], &arr[i]); // �ָ�����ԭʼ״̬��������һ������
    }
}

int main() {
    int arr[3];

    printf("������������ͬ��С��10���������֣��ÿո�ָ�����");
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

    printf("�������������Ҳ���ͬ�����з�ʽΪ��\n");
    permute(arr, 0, 2);

    return 0;
}