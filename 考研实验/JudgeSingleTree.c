//
// Created by 86159 on 2024/11/8.
//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct BiNode{
    char data;
    struct BiNode* lTree;
    struct BiNode* rTree;
}BiNode,*BiTree;

BiTree buildTree(char *string);
BiTree buildNode(char *string,int *idx);
int judge(BiTree biTree);
int judgeNode(BiTree biTree,int isL);

int main(){
    char *s = (char *) malloc(sizeof(char ));
    scanf("%s",s);
    BiTree tree = buildTree(s);
    judge(tree)? printf("是"): printf("否");
}

BiTree buildTree(char *string){
    int *idx = (int *) malloc(sizeof(int ));
    *idx = 0;
    return buildNode(string,idx);
}

BiTree buildNode(char *string,int *idx){
    if(*idx>= strlen(string) || string[*idx]=='#'){
        (*idx)++;
        return NULL;
    }
    BiNode *newTree = (BiNode*) malloc(sizeof(BiNode));
    newTree->data = string[*idx];
    (*idx)++;
    newTree->lTree = buildNode(string,idx);
    newTree->rTree = buildNode(string,idx);
    return newTree;
}


int judge(BiTree biTree){
    if(biTree==NULL)return 1;
    if(biTree->lTree!=NULL && biTree->rTree!=NULL)return 0;
    if(biTree->lTree!=NULL)return judgeNode(biTree->lTree,1);
    else return judgeNode(biTree->rTree,0);
}
int judgeNode(BiTree biTree,int isL){
    if(biTree==NULL)return 1;
    if(isL && biTree->rTree!=NULL)return 0;
    if(!isL && biTree->rTree!=NULL)return 0;
    return isL? judgeNode(biTree->lTree,1): judgeNode(biTree->rTree,0);
}