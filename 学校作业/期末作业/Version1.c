//
// Created by 86159 on 2023-06-05.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int mode;   //游玩模式
    int cards[15];   // 存各数字牌剩余数量
} Deck;   // 牌库结构体

typedef struct {
    int idx;   // 玩家编号
    int cards[5];   // 手牌
    int cardNum;   // 几张牌
    int sum;   // 总和
    int computer;   // 是否电脑
    float money;   // 赌资
    int vip;   // 是否 VIP - 暂未实现使用，仅有该属性
} Player;   // 玩家结构体

int decks[3][15] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1}
};


// 玩家初始化
Player playerInit(Player player) {
    player.sum = 0;
    player.cardNum = 0;
    return player;
}


// 快速排序 - 按牌面
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


// 快速排序 - 按赌资
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


// 输入玩家数组、游玩人数，得到胜利者 - 一般模式
int getWinnerBase(Player players[], int num) {
    quickSortSum(players, 0, num - 1);
    for (int i = 0; i < num; ++i) {
        if (players[i].sum <= 24) {
            return players[i].idx;
        }
    }
}


//输入玩家数组、游玩人数，得到胜利者 - 赌注模式
int getWinnerStake(Player players[], int num) {
    quickSortMoney(players, 0, num - 1);
    return players[0].idx;
}


// 牌库模式选择
Deck deckModeChoose(Deck deck) {
    int mode;   // 牌库模式
    printf("选择牌库模式：\n0、自定义牌组模式； 1、13 模式； 2、52 两王相等模式； 3、52 两王不等模式; \n");
    scanf("%d", &mode);
    // 牌库放牌
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


// 游玩过程 - 单次基础游玩
int playBase(Player players[], Deck deck, int playerNum) {
    int winner = -1, currentPlayer = 0, boom = 0;   // 胜利者、当前玩家、爆牌人数
    deck = deckModeChoose(deck);   // 牌库模式选择
//    for (int i = 0; i < 15; ++i) {
//        printf("%d ", deck.cards[i]);
//    }
    // 初始化玩家
    for (int i = 0; i < playerNum; ++i) {
        printf("%d 号玩家：\n", i);
        players[i] = playerInit(players[i]);
    }
    // 正式游戏
    while (winner < 0) {
        // 抽牌
        int card = rand() % 15;
        while (!deck.cards[card]) {
            card = rand() % 15;
        }
        deck.cards[card]--;
        card += 1;   // 由于牌面是 1-15，而储存是 0-14，故加一
        printf("\n%d 号玩家得到牌 %d，", currentPlayer, card);

        // 加牌
        players[currentPlayer].cards[players[currentPlayer].cardNum++] = card;
        players[currentPlayer].sum += card;
        printf("%d 号玩家目前有 %d 张牌", currentPlayer, players[currentPlayer].cardNum);

        // 情况判定：爆牌、自动胜利、是否开牌
        if (players[currentPlayer].sum > 24) {
            printf("\n%d 号玩家爆了", currentPlayer);
            boom++;
        } else if (players[currentPlayer].sum == 24) {
            printf("\n%d 号玩家达到 24 点，自动胜利",currentPlayer);
            winner = currentPlayer;
        }

        // 爆牌人数过多 某人直接胜利
        if (boom >= playerNum - 1) {
            winner = currentPlayer;
        }

        // 投票表决是否开牌：所有人牌数相同且大于等于 2 开启表决 -> 大于一半人同意则开牌
        if (currentPlayer == playerNum - 1 && players[currentPlayer].cardNum >= 2) {
            printf("\n请玩家选择是否开牌\n0、否；1、是");
            int votes = 0, tmp;   // 票数 投票人同意与否
            for (int i = 0; i < playerNum; ++i) {
                if (players[i].sum > 24) { continue; }   // 爆牌者跳过
                printf("\n%d 号玩家是否同意开牌\n", i);
                if (players[i].computer) {   // 是电脑-随机表决
                    tmp = rand() % 2;
                } else {
                    scanf("%d", &tmp);
                }
                votes += tmp;
                printf("%d 号玩家选 %d", i, tmp);
            }
            if (votes > (playerNum - boom) / 2) {
                printf("\n更多人同意开牌\n");
                winner = getWinnerBase(players, playerNum);
            } else {
                printf("\n更多人不同意开牌\n");
            }
        }

        // 下一个人
        currentPlayer = (currentPlayer + 1) % playerNum;
        while (players[currentPlayer].sum > 24) {
            currentPlayer = (currentPlayer + 1) % playerNum;
        }
    }
    return winner;
}


// 游玩过程 - 赌注模式
int playStake(Player players[], Deck deck, int playerNum, int freq) {
    float stakes[playerNum];
    while (freq--) {
        for (int i = 0; i < playerNum; ++i) {
            printf("请 %d 号玩家输入赌注\n", i);
            scanf("%f", &stakes[i]);
        }
        int winner = playBase(players, deck, playerNum);
        printf("\n本轮 %d 胜利\n\n", winner);
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


// 榜单输出
void listOut(Player players[], Deck deck, int playerNum) {
    printf("\n榜单如下：");
    for (int i = 0; i < playerNum; ++i) {
        if (deck.playMode) {
            printf("\n玩家编号 %d 总分 %d\n持有牌面", players[i].idx, players[i].sum);
            for (int j = 0; j < players[i].cardNum; ++j) {
                printf("%d ", players[i].cards[j]);
            }
        } else {
            printf("\n玩家编号 %d 总分 %f\n持有牌面", players[i].idx, players[i].money);
        }
    }
}


// 主函数
int main() {
    int nextGame = 1;   // 是否进行下一局游戏；1-是，进行；0-否，不进行
    while (nextGame) {
        Deck deck;
        int playerNum;   // 游玩人数

        // 玩家定义
        printf("输入游玩人数：\n");
        scanf("%d", &playerNum);
        Player players[playerNum];
        for (int i = 0; i < playerNum; ++i) {
            printf("\n%d 号玩家：\n", i);
            players[i].idx = i;
            players[i].money = 100;
            printf("  该玩家是： 0、真人； 1、电脑；\n");
            scanf("%d", &players[i].computer);
            printf("  该玩家是否 VIP： 0、否； 1、是；\n");
            scanf("%d", &players[i].vip);
//            players[i] = playerInit(players[i]);
        }
        printf("玩家定义完成\n");

        // 游玩模式选择
        printf("选择游玩模式：\n0、赌注模式； 1、常规模式；\n");
        scanf("%d", &deck.playMode);
        int freq;
        if (!deck.playMode) {
            printf("赌注模式下游玩轮数\n");
            scanf("%d", &freq);
        }

        // 输出榜单和胜利者
        int winner = deck.playMode ? playBase(players, deck, playerNum) : playStake(players, deck, playerNum, freq);
        listOut(players, deck, playerNum);
        printf("\n%d 号玩家胜利\n\n是否开启下一局\n0、否；1、是\n", winner);
        scanf("%d", &nextGame);
    }
    return 0;
}