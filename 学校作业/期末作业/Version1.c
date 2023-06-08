//
// Created by 86159 on 2023-06-05.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int mode;   //����ģʽ
    int cards[15];   // ���������ʣ������
} Deck;   // �ƿ�ṹ��

typedef struct {
    int idx;   // ��ұ��
    int cards[5];   // ����
    int cardNum;   // ������
    int sum;   // �ܺ�
    int computer;   // �Ƿ����
    float money;   // ����
    int vip;   // �Ƿ� VIP - ��δʵ��ʹ�ã����и�����
} Player;   // ��ҽṹ��

int decks[3][15] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1}
};


// ��ҳ�ʼ��
Player playerInit(Player player) {
    player.sum = 0;
    player.cardNum = 0;
    return player;
}


// �������� - ������
void quickSortSum(Player players[], int l, int r) {
    if (l >= r) { return; }
    int i = l - 1, j = r + 1, x = players[(l + r + 1) >> 1].sum;
    while (i < j) {
        do {
            i++;
        } while (players[i].sum > x);
        do {
            j--;
        } while (players[j].sum < x);
        if (i < j) {
            Player tmp = players[i];
            players[i] = players[j];
            players[j] = tmp;
        }
    }
    quickSortSum(players, l, i - 1);
    quickSortSum(players, i, r);
}


// �������� - ������
void quickSortMoney(Player players[], int l, int r) {
    if (l >= r) { return; }
    int i = l - 1, j = r + 1;
    float x = players[(l + r + 1) >> 1].money;
    while (i < j) {
        do {
            i++;
        } while (players[i].money > x);
        do {
            j--;
        } while (players[j].money < x);
        if (i < j) {
            Player tmp = players[i];
            players[i] = players[j];
            players[j] = tmp;
        }
    }
    quickSortMoney(players, l, i - 1);
    quickSortMoney(players, i, r);
}


// ����������顢�����������õ�ʤ���� - һ��ģʽ
int getWinnerBase(Player players[], int num) {
    quickSortSum(players, 0, num - 1);
    for (int i = 0; i < num; ++i) {
        if (players[i].sum <= 24) {
            return players[i].idx;
        }
    }
}


//����������顢�����������õ�ʤ���� - ��עģʽ
int getWinnerStake(Player players[], int num) {
    quickSortMoney(players, 0, num - 1);
    return players[0].idx;
}


// �ƿ�ģʽѡ��
Deck deckModeChoose(Deck deck) {
    int mode;   // �ƿ�ģʽ
    printf("ѡ���ƿ�ģʽ��\n0���Զ�������ģʽ�� 1��13 ģʽ�� 2��52 �������ģʽ�� 3��52 ��������ģʽ; \n");
    scanf("%d", &mode);
    // �ƿ����
    if (mode) {
        for (int i = 0; i < 15; ++i) {
            deck.cards[i] = decks[deck.playMode - 1][i];
        }
    } else {
        int tmp;
        for (int i = 0; i < 15; ++i) {
            scanf("%d", &tmp);
            deck.cards[i] = tmp;
        }
    }
    return deck;
}


// ������� - ���λ�������
int playBase(Player players[], Deck deck, int playerNum) {
    int winner = -1, currentPlayer = 0, boom = 0;   // ʤ���ߡ���ǰ��ҡ���������
    deck = deckModeChoose(deck);   // �ƿ�ģʽѡ��
//    for (int i = 0; i < 15; ++i) {
//        printf("%d ", deck.cards[i]);
//    }
    // ��ʼ�����
    for (int i = 0; i < playerNum; ++i) {
        printf("%d ����ң�\n", i);
        players[i] = playerInit(players[i]);
    }
    // ��ʽ��Ϸ
    while (winner < 0) {
        // ����
        int card = rand() % 15;
        while (!deck.cards[card]) {
            card = rand() % 15;
        }
        deck.cards[card]--;
        card += 1;   // ���������� 1-15���������� 0-14���ʼ�һ
        printf("\n%d ����ҵõ��� %d��", currentPlayer, card);

        // ����
        players[currentPlayer].cards[players[currentPlayer].cardNum++] = card;
        players[currentPlayer].sum += card;
        printf("%d �����Ŀǰ�� %d ����", currentPlayer, players[currentPlayer].cardNum);

        // ����ж������ơ��Զ�ʤ�����Ƿ���
        if (players[currentPlayer].sum > 24) {
            printf("\n%d ����ұ���", currentPlayer);
            boom++;
        } else if (players[currentPlayer].sum == 24) {
            printf("\n%d ����Ҵﵽ 24 �㣬�Զ�ʤ��",currentPlayer);
            winner = currentPlayer;
        }

        // ������������ ĳ��ֱ��ʤ��
        if (boom >= playerNum - 1) {
            winner = currentPlayer;
        }

        // ͶƱ����Ƿ��ƣ�������������ͬ�Ҵ��ڵ��� 2 ������� -> ����һ����ͬ������
        if (currentPlayer == playerNum - 1 && players[currentPlayer].cardNum >= 2) {
            printf("\n�����ѡ���Ƿ���\n0����1����");
            int votes = 0, tmp;   // Ʊ�� ͶƱ��ͬ�����
            for (int i = 0; i < playerNum; ++i) {
                if (players[i].sum > 24) { continue; }   // ����������
                printf("\n%d ������Ƿ�ͬ�⿪��\n", i);
                if (players[i].computer) {   // �ǵ���-������
                    tmp = rand() % 2;
                } else {
                    scanf("%d", &tmp);
                }
                votes += tmp;
                printf("%d �����ѡ %d", i, tmp);
            }
            if (votes > (playerNum - boom) / 2) {
                printf("\n������ͬ�⿪��\n");
                winner = getWinnerBase(players, playerNum);
            } else {
                printf("\n�����˲�ͬ�⿪��\n");
            }
        }

        // ��һ����
        currentPlayer = (currentPlayer + 1) % playerNum;
        while (players[currentPlayer].sum > 24) {
            currentPlayer = (currentPlayer + 1) % playerNum;
        }
    }
    return winner;
}


// ������� - ��עģʽ
int playStake(Player players[], Deck deck, int playerNum, int freq) {
    float stakes[playerNum];
    while (freq--) {
        for (int i = 0; i < playerNum; ++i) {
            printf("�� %d ����������ע\n", i);
            scanf("%f", &stakes[i]);
        }
        int winner = playBase(players, deck, playerNum);
        printf("\n���� %d ʤ��\n\n", winner);
        for (int i = 0; i < playerNum; ++i) {
            if (i == winner) {
                players[i].money += stakes[i] * (playerNum - 1);
            } else {
                players[i].money -= stakes[i];
            }
        }
    }
    return getWinnerStake(players, playerNum);
}


// �����
void listOut(Player players[], Deck deck, int playerNum) {
    printf("\n�����£�");
    for (int i = 0; i < playerNum; ++i) {
        if (deck.playMode) {
            printf("\n��ұ�� %d �ܷ� %d\n��������", players[i].idx, players[i].sum);
            for (int j = 0; j < players[i].cardNum; ++j) {
                printf("%d ", players[i].cards[j]);
            }
        } else {
            printf("\n��ұ�� %d �ܷ� %f\n��������", players[i].idx, players[i].money);
        }
    }
}


// ������
int main() {
    int nextGame = 1;   // �Ƿ������һ����Ϸ��1-�ǣ����У�0-�񣬲�����
    while (nextGame) {
        Deck deck;
        int playerNum;   // ��������

        // ��Ҷ���
        printf("��������������\n");
        scanf("%d", &playerNum);
        Player players[playerNum];
        for (int i = 0; i < playerNum; ++i) {
            printf("\n%d ����ң�\n", i);
            players[i].idx = i;
            players[i].money = 100;
            printf("  ������ǣ� 0�����ˣ� 1�����ԣ�\n");
            scanf("%d", &players[i].computer);
            printf("  ������Ƿ� VIP�� 0���� 1���ǣ�\n");
            scanf("%d", &players[i].vip);
//            players[i] = playerInit(players[i]);
        }
        printf("��Ҷ������\n");

        // ����ģʽѡ��
        printf("ѡ������ģʽ��\n0����עģʽ�� 1������ģʽ��\n");
        scanf("%d", &deck.playMode);
        int freq;
        if (!deck.playMode) {
            printf("��עģʽ����������\n");
            scanf("%d", &freq);
        }

        // ����񵥺�ʤ����
        int winner = deck.playMode ? playBase(players, deck, playerNum) : playStake(players, deck, playerNum, freq);
        listOut(players, deck, playerNum);
        printf("\n%d �����ʤ��\n\n�Ƿ�����һ��\n0����1����\n", winner);
        scanf("%d", &nextGame);
    }
    return 0;
}