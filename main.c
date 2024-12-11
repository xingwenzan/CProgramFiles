#include "stdio.h"
#include "stdlib.h"

// 链表
typedef struct LineNode {
    int data;
    struct LineNode *next;
} LineNode, *LineTable;


LineTable create_tail(int special);
int judge(LineTable table);
void outTable(LineTable table);
void reserve(LineTable head);
LineTable merge(LineTable A, LineTable B);
LineTable merge_reserve(LineTable A, LineTable B);
int ring_judge(LineTable table);


int main() {

    int choose;
    printf("请选择进行的操作：\n1.链表逆置\n2.链表合并\n3.链表合并并逆置\n4.链表判断连续元素之间是否差值绝对值不大于2\n");
    scanf("%d", &choose);
    switch (choose) {
        case 1: {//链表逆置
            LineTable A = create_tail(0);
            reserve(A);
            outTable(A);
            break;
        }
        case 2: {// 链表合并
            LineTable A = create_tail(0);
            LineTable B = create_tail(0);
            LineTable C = merge(A, B);
            outTable(C);
            break;
        }
        case 3: {// 链表合并并逆置
            LineTable A = create_tail(0);
            LineTable B = create_tail(0);
            LineTable C = merge_reserve(A, B);
            outTable(C);
            break;
        }
        case 4: {// 链表判断连续元素之间是否差值绝对值不大于2
            LineTable A = create_tail(1);
            int tmp = ring_judge(A);
            if (tmp == -1) {
                printf("列表不符合标准\n");
            } else if (tmp == 0) {
                printf("差值存在大于 2\n");
            } else {
                printf("差值不存在大于 2\n");
            }
            break;
        }
        default:
            printf("无效选项\n");
    }


}

/**
 * 链表创建 - 尾插法
 * @param special 特殊用途：0-无；1-有环（表尾指向头节点的下一个节点，保证环中每个节点都有数据）
 * @use 输入链表元素的数据值，各个值之间用空格、回车连接，最后用一个单独的 ‘0’ 结尾
 * @return 带头节点的单链表，头节点的 data 存储特殊标识
 */
LineTable create_tail(int special) {
    LineTable ans = (LineNode *) malloc(sizeof(LineNode));
    ans->data = special;
    ans->next = NULL;
    LineNode *tmp = ans;

    printf("请输入链表元素，并以 “0” 结尾：\n");

    int a;
    while (1) {
        scanf("%d", &a);
        if (a == 0)break;
        tmp->next = (LineNode *) malloc(sizeof(LineNode));
        tmp->next->data = a;
        tmp->next->next = NULL;
        tmp = tmp->next;
    }
    if (special) {
        tmp->next = ans->next;
    }

    return ans;
}

/**
 * 判断链表状态、类型
 * @param table 链表（头结点）
 * @return 链表类型
 */
int judge(LineTable table) {
    if (table == NULL || table->next == NULL) {
        printf("NULL\n");
        return -1;
    }
    if (table->data == 0) {
        printf("normal\n");
    } else {
        printf("special:%d\n", table->data);
    }
    return table->data;
}

/**
 * 链表输出
 * @param table(链表)
 */
void outTable(LineTable table) {
    if (judge(table) != 0)return;
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
    if (judge(head) != 0)return;

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
    if (judge(A) != 0 || judge(B) != 0)return NULL;

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
LineTable merge_reserve(LineTable A, LineTable B) {
    if (judge(A) != 0 || judge(B) != 0)return NULL;

    LineTable C = A, tmp = B;
    A = A->next;
    B = B->next;
    free(tmp);

    C->next = NULL;
    while (A != NULL && B != NULL) {
        if (A->data < B->data) {
            tmp = A;
            A = A->next;
            tmp->next = C->next;
            C->next = tmp;
        } else {
            tmp = B;
            B = B->next;
            tmp->next = C->next;
            C->next = tmp;
        }
    }

    while (A != NULL) {
        tmp = A;
        A = A->next;
        tmp->next = C->next;
        C->next = tmp;
    }

    while (B != NULL) {
        tmp = B;
        B = B->next;
        tmp->next = C->next;
        C->next = tmp;
    }

    return C;
}

/**
 * 链表判断连续元素之间是否差值绝对值不大于2
 * @param table 链表
 * @return -1：不合法链表；0：存在大于；1：不存在大于
 */
int ring_judge(LineTable table) {
    if (judge(table) != 1)return -1;
    LineNode *cur = table->next;
    int tmp;
    while (cur->next != table->next) {
        tmp = cur->data - cur->next->data;
        if (tmp > 2 || tmp < -2)return 0;
        cur = cur->next;
    }
    tmp = cur->data - cur->next->data;
    return tmp < 2 && tmp > -2;
}