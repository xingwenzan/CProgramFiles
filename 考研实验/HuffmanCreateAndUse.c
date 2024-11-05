//
// Created by 86159 on 2024/11/5.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 10

typedef struct BiNode {
    struct BiNode *lTree;
    struct BiNode *rTree;
    int weight;
    char sign;
} BiNode, *BiTree;

typedef struct Heap {
    int nodesNum;
    BiTree Nodes[MAX];
} Heap;

void init(Heap *heap);

void down(Heap *heap, int idx);

void swap(Heap *heap, int st, int ed);

void add(Heap *heap, BiTree new);

void up(Heap *heap, int idx);

BiTree removeFirst(Heap *heap);

BiTree getHuffman(Heap *heap);

int main() {
    int n;
    printf("输入有几个字符：");
    scanf("%d", &n);
    printf("\n输入字符和权值：");
    Heap *h = (Heap *) malloc(sizeof(Heap));
    h->nodesNum = n;
    for (int i = 0; i < n; ++i) {
        h->Nodes[i] = (BiNode *) malloc(sizeof(BiNode));
        h->Nodes[i]->lTree = NULL;
        h->Nodes[i]->rTree = NULL;
        scanf("%d %c", &h->Nodes[i]->weight, &h->Nodes[i]->sign);
    }

    init(h);
    BiTree Huffman = getHuffman(h);

    printf("\n输入编码：");
    char *string = (char *) malloc(sizeof(char));
    scanf("%s", string);


    char c;
    BiNode *tmp = Huffman;
    for (int i = 0; i < strlen(string); ++i) {
        c = string[i];
        if (c == '0') {
            tmp = tmp->lTree;
        } else {
            tmp = tmp->rTree;
        }

        if (tmp->sign != '*') {
            printf("%c", tmp->sign);
            tmp = Huffman;
        }
    }
}

void init(Heap *heap) {
    for (int i = heap->nodesNum; i < MAX; ++i) {
        heap->Nodes[i] = NULL;
    }
    for (int i = heap->nodesNum/2; i >= 0; --i) {
        down(heap, i);
    }
}

void down(Heap *heap, int idx) {
    if (idx >= heap->nodesNum)return;
    int tmp = idx;
    if (idx * 2 + 1<heap->nodesNum && heap->Nodes[tmp]->weight > heap->Nodes[idx * 2 + 1]->weight)tmp = idx * 2 + 1;
    if (idx * 2 + 2<heap->nodesNum && heap->Nodes[tmp]->weight > heap->Nodes[idx * 2 + 2]->weight)tmp = idx * 2 + 2;
    if (tmp != idx) {
        swap(heap, idx, tmp);
        down(heap, tmp);
    }
}

void swap(Heap *heap, int st, int ed) {
    BiTree tmp = heap->Nodes[st];
    heap->Nodes[st] = heap->Nodes[ed];
    heap->Nodes[ed] = tmp;
}


BiTree getHuffman(Heap *heap) {
    while (heap->nodesNum > 1) {
        BiTree min0 = removeFirst(heap);
        BiTree min1 = removeFirst(heap);
        BiTree newTree = (BiNode *) malloc(sizeof(BiNode));
        newTree->lTree = min0;
        newTree->rTree = min1;
        newTree->weight = min1->weight + min0->weight;
        newTree->sign = '*';
        add(heap, newTree);
    }
    return heap->Nodes[0];
}

BiTree removeFirst(Heap *heap) {
    BiTree ans = heap->Nodes[0];
    heap->Nodes[0] = heap->Nodes[--heap->nodesNum];
    down(heap, 0);
    return ans;
}

void add(Heap *heap, BiTree new) {
    heap->Nodes[heap->nodesNum++] = new;
    up(heap, heap->nodesNum - 1);
}

void up(Heap *heap, int idx) {
    while (idx != 0) {
        if (heap->Nodes[idx]->weight < heap->Nodes[idx / 2]->weight)swap(heap, idx, idx / 2);
        idx /= 2;
    }
}