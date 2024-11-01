//
// Created by 86159 on 2024/11/1.
//
#include "stdlib.h"
#include "stdio.h"

typedef struct BiNode {
    int data;
    struct BiNode *lTree;
    struct BiNode *rTree;
} BiNode, *BiTree;

BiTree add(BiTree tree, int key);

BiTree create(int key);

void inOrder(BiTree tree);
int getAns(BiTree tree,int key,int num);


int main() {
    BiTree root = NULL;
    int tmp;
    while (1) {
        scanf("%d", &tmp);
        if (tmp == 0)break;
        root = add(root, tmp);
    }

    inOrder(root);

    scanf("%d", &tmp);

    int ans = getAns(root,tmp,0);
    printf("\nANS = %d",ans);
}


BiTree add(BiTree tree, int key) {
    if (tree == NULL) {
        return create(key);;
    }

    if (key < tree->data)tree->lTree = add(tree->lTree, key);
    else if(key > tree->data) tree->rTree = add(tree->rTree, key);

    return tree;
}

BiTree create(int key) {
    BiTree tmp = (BiNode *) malloc(sizeof(BiNode));
    tmp->lTree = NULL;
    tmp->rTree = NULL;
    tmp->data = key;

    return tmp;
}

void inOrder(BiTree tree) {
    if (tree == NULL)return;

    inOrder(tree->lTree);
    printf("%d ", tree->data);
    inOrder(tree->rTree);
}

int getAns(BiTree tree,int key,int num){

    if (tree == NULL)return num;

    num = getAns(tree->lTree,key,num);
    if(tree->data<=key){
        num++;
        printf("%d ", tree->data);
    }
    num = getAns(tree->rTree,key,num);

    return num;
}