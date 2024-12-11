#include "stdio.h"
#include "stdlib.h"

// ����
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
    printf("��ѡ����еĲ�����\n1.��������\n2.����ϲ�\n3.����ϲ�������\n4.�����ж�����Ԫ��֮���Ƿ��ֵ����ֵ������2\n");
    scanf("%d", &choose);
    switch (choose) {
        case 1: {//��������
            LineTable A = create_tail(0);
            reserve(A);
            outTable(A);
            break;
        }
        case 2: {// ����ϲ�
            LineTable A = create_tail(0);
            LineTable B = create_tail(0);
            LineTable C = merge(A, B);
            outTable(C);
            break;
        }
        case 3: {// ����ϲ�������
            LineTable A = create_tail(0);
            LineTable B = create_tail(0);
            LineTable C = merge_reserve(A, B);
            outTable(C);
            break;
        }
        case 4: {// �����ж�����Ԫ��֮���Ƿ��ֵ����ֵ������2
            LineTable A = create_tail(1);
            int tmp = ring_judge(A);
            if (tmp == -1) {
                printf("�б����ϱ�׼\n");
            } else if (tmp == 0) {
                printf("��ֵ���ڴ��� 2\n");
            } else {
                printf("��ֵ�����ڴ��� 2\n");
            }
            break;
        }
        default:
            printf("��Чѡ��\n");
    }


}

/**
 * ������ - β�巨
 * @param special ������;��0-�ޣ�1-�л�����βָ��ͷ�ڵ����һ���ڵ㣬��֤����ÿ���ڵ㶼�����ݣ�
 * @use ��������Ԫ�ص�����ֵ������ֵ֮���ÿո񡢻س����ӣ������һ�������� ��0�� ��β
 * @return ��ͷ�ڵ�ĵ�����ͷ�ڵ�� data �洢�����ʶ
 */
LineTable create_tail(int special) {
    LineTable ans = (LineNode *) malloc(sizeof(LineNode));
    ans->data = special;
    ans->next = NULL;
    LineNode *tmp = ans;

    printf("����������Ԫ�أ����� ��0�� ��β��\n");

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
 * �ж�����״̬������
 * @param table ����ͷ��㣩
 * @return ��������
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
 * �������
 * @param table(����)
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
 * ��������
 * @param head (����ͷָ��)
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
 * ����ϲ�
 * @param A������ A��
 * @param B������ B��
 * @return �ϲ��������
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
 * ��������ϲ�
 * @param A ������ A��
 * @param B ������ B��
 * @return ����ϲ��������
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
 * �����ж�����Ԫ��֮���Ƿ��ֵ����ֵ������2
 * @param table ����
 * @return -1�����Ϸ�����0�����ڴ��ڣ�1�������ڴ���
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