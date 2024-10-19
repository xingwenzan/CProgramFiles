//
// Created by 86159 on 2024/10/19.
//
#include <stdio.h>

typedef struct {
    int *arr;
    int len;
} heap;

void adjust(heap *h);

heap init(int *arr, int len);

void swap(heap *h, int p1, int p2);

void down(heap *h, int idx);

void printHeap(heap *h);


int main() {
    int a[7];
    for (int i = 0; i < 7; ++i) {
        scanf("%d", &a[i]);
    }

    heap myHeap = init(a, 7);

    for (int i = 0; i < 7; ++i) {
        printf("%d ", myHeap.arr[i]);
    }

    printf("\n");

    printHeap(&myHeap);

    return 0;
}


heap init(int *arr, int len) {
    heap h;
    h.arr = arr;
    h.len = len;

    adjust(&h);

    return h;
}

void adjust(heap *h) {
    for (int i = h->len / 2; i >= 0; --i) {
        down(h, i);
    }
}

void down(heap *h, int idx) {
    if (idx >= h->len / 2)return;
    int tmp = idx;
    if (h->arr[tmp] > h->arr[2 * idx + 1])tmp = 2 * idx + 1;
    if (h->arr[tmp] > h->arr[2 * idx + 2])tmp = 2 * idx + 2;
    if (tmp != idx) {
        swap(h, idx, tmp);
        down(h, tmp);
    }
}

void swap(heap *h, int p1, int p2) {
    int tmp = h->arr[p1];
    h->arr[p1] = h->arr[p2];
    h->arr[p2] = tmp;
}

void printHeap(heap *h) {
    while (h->len > 0) {
        printf("%d ", h->arr[0]);
        h->arr[0] = h->arr[--h->len];
        down(h, 0);
    }
}