#include "stdio.h"
#include "stdlib.h"

typedef struct LineNode {
    int data;
    struct LineNode *next;
} LineNode, *LineTable;

/**
 * 链表创建
 * @use 输入链表元素的数据值，各个值之间用空格、回车连接，最后用一个单独的 ‘0’ 结尾
 * @return 链表
 */
LineTable create() {
    LineTable ans = (LineNode *) malloc(sizeof(LineNode));
    ans->data = -1;
    ans->next = NULL;
    LineNode *tmp = ans;

    int a;
    while (1) {
        scanf("%d", &a);
        if (a == 0)break;
        tmp->next = (LineNode *) malloc(sizeof(LineNode));
        tmp->next->data = a;
        tmp->next->next = NULL;
        tmp = tmp->next;
    }

    return ans;
}

/**
 * 链表输出
 * @param table(链表)
 */
void outTable(LineTable table) {
    if (table == NULL) {
        printf("NULL");
        return;
    }
    table = table->next;
    while (table != NULL) {
        printf("%d ", table->data);
        table = table->next;
    }
    printf("\n");
}


/**
 * 链表逆置
 * @param head (链表头指针)
 */
void reserve(LineTable head) {
    if (head == NULL || head->next == NULL) {
        printf("NULL");
        return;
    }
    LineNode *tail = head->next, *tmp = tail->next;
    while (tmp != NULL) {
        tail->next = tmp->next;
        tmp->next = head->next;
        head->next = tmp;

        tmp = tail->next;
    }
}

/**
 * 链表合并
 * @param A（链表 A）
 * @param B（链表 B）
 * @return 合并后的链表
 */
LineTable merge(LineTable A, LineTable B) {
    LineTable C = A, tmp = B;
    A = A->next;
    B = B->next;

    free(tmp);
    tmp = C;

    while (A != NULL && B != NULL) {
        if (A->data < B->data) {
            tmp->next = A;
            A = A->next;
        } else {
            tmp->next = B;
            B = B->next;
        }
        tmp = tmp->next;
    }
    if (A == NULL) {
        tmp->next = B;
    }
    if (B == NULL) {
        tmp->next = A;
    }

    return C;
}

/**
 * 链表逆序合并
 * @param A （链表 A）
 * @param B （链表 B）
 * @return 逆序合并后的链表
 */
LineTable merge_reserve(LineTable A,LineTable B){
    LineTable C = A,tmp = B;
    A = A->next;B = B->next;
    free(tmp);

    C->next = NULL;
    while (A!=NULL && B!=NULL){
        if(A->data<B->data){
            tmp = A;A = A->next;
            tmp->next = C->next;
            C->next = tmp;
        } else{
            tmp = B;B = B->next;
            tmp->next = C->next;
            C->next = tmp;
        }
    }

    while (A!=NULL){
        tmp = A;A = A->next;
        tmp->next = C->next;
        C->next = tmp;
    }

    while (B!=NULL){
        tmp = B;B = B->next;
        tmp->next = C->next;
        C->next = tmp;
    }

    return C;
}

int main() {

    int choose;
    printf("请选择进行的操作：\n1.链表逆置\n2.链表合并\n3.链表合并并逆置\n");
    scanf("%d", &choose);
    switch (choose) {
        case 1: {//链表逆置
            LineTable A = create();
            reserve(A);
            outTable(A);
            break;
        }
        case 2: {// 链表合并
            LineTable A = create();
            LineTable B = create();
            LineTable C = merge(A, B);
            outTable(C);
            break;
        }
        case 3:{
            LineTable A = create();
            LineTable B = create();
            LineTable C = merge_reserve(A, B);
            outTable(C);
            break;
        }
        default:
            printf("无效选项\n");
    }


}