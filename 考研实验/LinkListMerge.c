//
// Created by 86159 on 2024/10/25.
//
#include "stdio.h"
#include "stdlib.h"

//---------------------------------------------
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode, *LinkList;
//----------------------------------------------

void printLink(LinkList p){
    LinkNode *t = p->next;
    while (t!=p){
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");
}

LinkList reSort(LinkList p1,LinkList p2){
    LinkNode *t1 = p1->next, *t2 = p2->next,*tmp;
    LinkList ans = p1;
    ans->next = ans;

    while (t1!=p1 && t2!=p2){
        if(t1->data >= t2->data){
            tmp = t1;
            t1 = t1->next;
            tmp->next = ans->next;
            ans->next = tmp;
            tmp = NULL;
        } else{
            tmp = t2;
            t2 = t2->next;
            tmp->next = ans->next;
            ans->next = tmp;
            tmp = NULL;
        }
    }
    while (t1!=p1){
        tmp = t1;
        t1 = t1->next;
        tmp->next = ans->next;
        ans->next = tmp;
        tmp = NULL;
    }
    while (t2!=p2){
        tmp = t2;
        t2 = t2->next;
        tmp->next = ans->next;
        ans->next = tmp;
        tmp = NULL;
    }

    free(p2);
    return ans;
}

int main() {
    LinkList a = (LinkNode *) malloc(sizeof(LinkNode)), b = (LinkNode *) malloc(sizeof(LinkNode));
    a->next = a;
    b->next = b;

    LinkNode *tmp;
    for (int i = 0; i < 5; ++i) {
        tmp = (LinkNode *) malloc(sizeof(LinkNode));
        tmp->data = 2 * i + 1;
        tmp->next = a->next;
        a->next = tmp;
        tmp = NULL;
    }

    for (int i = 0; i < 3; ++i) {
        tmp = (LinkNode *) malloc(sizeof(LinkNode));
        tmp->data = 2 * i;
        tmp->next = b->next;
        b->next = tmp;
        tmp = NULL;
    }

    printLink(a);
    printLink(b);

    LinkList ans = reSort(a,b);
    printLink(ans);
}