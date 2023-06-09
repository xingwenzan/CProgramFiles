//
// Created by 86159 on 2023-06-09.
//
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


/* �ƿ�ṹ������
 * playMode ����ģʽ
 * cards[15] ���������ʣ������
 * scoreMode �Ʒ�ģʽ
 * // ͨ�������Ʊ������ģʽ���أ�0 ��/�� 1 ��/��
 * // �ӵ͵��ߣ��Զ���Ȩ�ء���ͬ�Ʋ�ͬȨ�ء����� 10 �� 10��A �ɴ��� 1 �� 11
 * weight[15] ����Ȩ��
 */
typedef struct {
    int playMode;
    int cards[15];
    int scoreMode;
    float weight[15];
} Deck;

typedef struct {
    int idx;   // ��ұ��
    int cards[5];   // ����
    int cardNum;   // ������
    float sum;   // �ܺ�
    int computer;   // �Ƿ����   1 �� 0 ��
    float money;   // ����
    int vip;   // �Ƿ��� VIP   1 �� 0 ��
    int out;   // �Ƿ���̭   1 �� 0 ��
} Player;   // ��ҽṹ��

int decks[4][15] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1}
};

// ������ʾ   t(ten) 10   w С��   W ����
char cardsShow[15] = {'A', '2', '3', '4', '5', '6', '7', '8', '9',
                      't', 'J', 'Q', 'K', 'w', 'W'};


// ��ҳ�ʼ��
Player playerInit(Player player) {
    player.sum = 0;
    player.cardNum = 0;
    return player;
}


// �ƿ�ģʽѡ��/��ʼ��
Deck deckModeChoose(Deck deck) {
    int mode;   // �ƿ�ģʽ
    printf("ѡ���ƿ�ģʽ��\n0���Զ�������ģʽ��1��13 ģʽ��2��4*10 ģʽ��3��52 ��С��ģʽ��4��52 ��С��ģʽ;\n");
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

    // �������������
    printf("�Ƿ������е�������ģʽ��0����1���ǣ�\n");
    printf("�Զ�������Ȩ��\n");
    scanf("%d", &mode);
    deck.scoreMode = mode;
    if (mode) {   // �Զ���Ȩ��
        printf("�Ƿ�ͬ�Ʋ�ͬȨ��\n");
        scanf("%d", &mode);
        deck.scoreMode += mode << 1;
        if (mode) {   // �����ͬȨ��
            printf("������ 15 ���Ƶĸ���Ȩ��\n");
            for (int i = 0; i < 15; ++i) {
                scanf("%f", &deck.weight[i]);
            }
        } else {   // �����ͬȨ��
            printf("�������Ƶ�Ȩ��\n");
            float tmp;
            scanf("%f", &tmp);
            for (int i = 0; i < 15; ++i) {
                deck.weight[i] = tmp;
            }
        }
    } else {    // ���Զ���
        for (int i = 0; i < 15; ++i) {
            deck.weight[i] = 1;
        }
    }
    printf("�Ƿ� J��Q��K��������Ϊ 10\n");
    scanf("%d", &mode);
    deck.scoreMode += mode << 2;
    printf("�Ƿ� A ����Ϊ��������� 1 �� 11\n");
    scanf("%d", &mode);
    deck.scoreMode += mode << 3;
    return deck;
}


// ���� ʹ������ͣ��ֱ������������ʱ�������У�˳����տ���̨
void GoOn(){
    char op[10];
    // ��ҳ 2 �Σ���һ��ʹ��һ���˽���հ�ҳ���ڶ�������һ�������룬�ӿհ�ҳ��������ҳ�棬��֤������������
    for (int i = 0; i < 2; ++i) {
        printf("\n���������ַ�����\n");
        scanf("%s",op);
        system("cls");   // ��տ���̨�����������ֱ�����Ϸ���ʹ�����˿�������
    }
}


// ��ʾ��ҵ�ǰ�ƺ��ܵ���
void showCards(Player player){
    printf("\n��Ŀǰ�����У�\n");
    for (int i = 0; i < player.cardNum; ++i) {
        printf("%c ",cardsShow[player.cards[i]-1]);
    }
    printf("\n��Ŀǰ�ĵ����ܺ��ǣ�%f\n",player.sum);
}


// ��ʾ��ǰ��������ʽ�
void showMoney(Player players[],int playerNum){
    printf("\n��ǰ������ʽ����£�\n");
    for (int i = 0; i < playerNum; ++i) {
        printf("%d ����ң�%f ��\n",i,players[i].money);
    }
}


// �����
void listOut(Player players[], Deck deck, int playerNum) {
    printf("\n�����£�");
    for (int i = 0; i < playerNum; ++i) {
        if (deck.playMode) {
            printf("\n��ұ�� %d �ܷ� %f\n��������", players[i].idx, players[i].sum);
            for (int j = 0; j < players[i].cardNum; ++j) {
                printf("%c ", cardsShow[players[i].cards[j] - 1]);
            }
        } else {
            printf("\n��ұ�� %d �ܷ� %f", players[i].idx, players[i].money);
        }
    }
}


// ��������
float stakeInput(Player player){
    float stake;
    scanf("%f", &stake);
    while (stake<=0 || stake>player.money){
        printf("���Ķ������벻�Ϸ�������Ӧ���ڴ�������С������ȫ���ʽ�����������\n����ȫ���ʽ�Ϊ %f\n",player.money);
        scanf("%f", &stake);
    }
    return stake;
}


// �������� - ���������
void quickSortCard(Player player, int l, int r) {
    if (l >= r) { return; }
    int i = l - 1, j = r + 1, x = player.cards[(l + r + 1) >> 1];
    while (i < j) {
        do {
            i++;
        } while (player.cards[i] > x);
        do {
            j--;
        } while (player.cards[j] < x);
        if (i < j) {
            int tmp = player.cards[i];
            player.cards[i] = player.cards[j];
            player.cards[j] = tmp;
        }
    }
    quickSortCard(player, l, i - 1);
    quickSortCard(player, i, r);
}


// �������� - ������
void quickSortSum(Player players[], int l, int r) {
    if (l >= r) { return; }
    int i = l - 1, j = r + 1;
    float x = players[(l + r + 1) >> 1].sum;
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


// ��������
float score(Deck deck, Player player) {
    Player tmp = player;
    quickSortCard(tmp, 0, player.cardNum - 1);
    float tmpScore = 0;
    for (int i = 0; i < tmp.cardNum; ++i) {
        int card = tmp.cards[i];
        float weight = deck.weight[i];
        if (card > 10) {
            tmpScore += 10 * weight;
        } else if (card == 1) {
            tmpScore += (tmpScore + weight * 11 > 24 ? 1.0f : 11.0f) * weight;
        } else {
            tmpScore += (float) card * weight;
        }
    }
    return tmpScore;
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


// ������� - ���λ�������
int playBase(Player players[], Deck deck, int playerNum) {
    srand(time(NULL));
    int winner = -1;   // ʤ����
    deck = deckModeChoose(deck);   // �ƿ�ģʽѡ��
//    for (int i = 0; i < 15; ++i) {
//        printf("%d ", deck.cards[i]);
//    }
    // ��ʼ�����
    for (int i = 0; i < playerNum; ++i) {
        printf("%d ����ҳ�ʼ�����\n", i);
        players[i] = playerInit(players[i]);
    }

    GoOn();   // ��տ���̨

    // ��ʽ��Ϸ
    while (winner < 0) {
        int boom = 0;   // ��������
        // ���ڴ����һ��ʣ��δ�������Ӧ�ó鵽���ƣ�����Ƿ� VIP ʹ��
        int nextCards[playerNum];
        for (int i = 0; i < playerNum; ++i) {   // ����
            if (players[i].sum < 24 && !players[i].out) {   // ֻ��δ��̭��δ������ҳ�
                int tmp = rand() % 15;
                deck.cards[tmp]--;
                nextCards[i] = tmp + 1;   // ���������� 1-15���������� 0-14���ʼ�һ
            } else {
                nextCards[i] = 0;
                boom++;
            }
        }

        if (boom < playerNum - 1) {   // û�кܶ��˱���
            // ѭ��ÿ����
            for (int i = 0; i < playerNum && winner < 0; ++i) {
                int card = nextCards[i], need = 1;   // ��ǰ���� �Ƿ�Ҫ��

                if (players[i].sum >= 24 || players[i].out) {   // ���ƻ���ֱ̭������
                    continue;
                } else {
                    // ���ж��Ƿ����
                    if (players[i].computer) {
                        // ���ж��Ƿ��� VIP
                        if (players[i].vip) {
                            Player tmp = players[i];
                            tmp.cards[tmp.cardNum++] = card;
                            tmp.sum = score(deck, tmp);   // ���
                            need = tmp.sum > 24 ? 0 : 1;   // ����ӽ�ȥ������Ҫ������Ҫ
                        } else {
                            need = rand() % 2;
                        }
                    } else {   // ����
                        if (players[i].vip) {   // �� VIP
                            printf("%d ����ң������һ������ %c\n", i, cardsShow[card - 1]);
                        }
                        printf("%d ����ң����Ƿ�Ҫ�����ƣ�\n0����1����\n", i);
                        scanf("%d", &need);
                    }
                }

                if (need) {   // Ҫ��
                    printf("\n%d ����ҵõ��� %c��", i, cardsShow[card - 1]);

                    // ����
                    players[i].cards[players[i].cardNum++] = card;
                    players[i].sum = score(deck, players[i]);   // ���
                    printf("%d �����Ŀǰ�� %d ����\n", i, players[i].cardNum);

                    // ����ж������ơ��Զ�ʤ�����Ƿ���
                    if (players[i].sum > 24) {
                        printf("\n%d ����ұ���", i);
                        boom++;
                    } else if (players[i].sum == 24) {
                        printf("\n%d ����Ҵﵽ 24 �㣬�Զ�ʤ��", i);
                        winner = i;
                    }
                }

                showCards(players[i]);   // ��ʾ��ɫ���ƺ��ܵ���
                GoOn();   // ��տ���̨

            }
        } else {   // ������������ δ�������ֱ��ʤ��
            for (int i = 0; i < playerNum && winner < 0; ++i) {
                if (players[i].sum < 24) {
                    winner = i;
                }
            }
        }

        // ͶƱ����Ƿ��� -> ����һ����ͬ������
        printf("\n�����ѡ���Ƿ���\n0����1����");
        int votes = 0, tmp;   // Ʊ�� ͶƱ��ͬ�����
        for (int i = 0; i < playerNum; ++i) {
            if (players[i].sum > 24 || players[i].out) { continue; }   // ���ƻ���̭������
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

        GoOn();   // ��տ���̨

    }
    return winner;
}


// ������� - ��עģʽ
int playStake(Player players[], Deck deck, int playerNum, int freq) {
    float stakes[playerNum];
    while (freq--) {
        for (int i = 0; i < playerNum; ++i) {
            printf("�� %d ����������ע\n", i);
            stakes[i] = stakeInput(players[i]);
        }
        int winner = playBase(players, deck, playerNum);
        printf("\n���� %d ʤ��\n\n", winner);
        for (int i = 0; i < playerNum; ++i) {
            if (i == winner) {
                players[i].money += stakes[i] * (float) (playerNum - 1);
            } else {
                players[i].money -= stakes[i];
                players[i].out = players[i].money<=0?1:0;   // �ʽ�С�ڵ��� 0 �Ʋ���̭
            }
        }

        showMoney(players,playerNum);   // ��������ʣ���ʽ�
        GoOn();   // ��տ���̨

    }
    return getWinnerStake(players, playerNum);
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
            printf("%d ����ң�\n", i);
            players[i].out = 0;
            players[i].idx = i;
            players[i].money = 100;
            printf("  ������ǣ� 0�����ˣ� 1�����ԣ�\n");
            scanf("%d", &players[i].computer);
            printf("  ������Ƿ� VIP�� 0���� 1���ǣ�\n");
            scanf("%d", &players[i].vip);
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