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
        swap(&arr[start], &arr[i]); // 恢复数组原始状态，方便下一次排列
    }
}

int main() {
    int arr[3];

    printf("请输入三个不同且小于10的整数数字（用空格分隔）：");
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

    printf("三个数字所有且不相同的排列方式为：\n");
    permute(arr, 0, 2);

    return 0;
}