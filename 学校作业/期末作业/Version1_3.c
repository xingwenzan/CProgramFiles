//
// Created by 86159 on 2023-06-09.
//
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


/* 牌库结构体属性
 * playMode 游玩模式
 * cards[15] 存各数字牌剩余数量
 * scoreMode 计分模式
 * // 通过二进制编码代表模式开关，0 关/否 1 开/是
 * // 从低到高：自定义权重、不同牌不同权重、大于 10 变 10、A 可代表 1 或 11
 * weight[15] 各牌权重
 */
typedef struct {
    int playMode;
    int cards[15];
    int scoreMode;
    float weight[15];
} Deck;

typedef struct {
    int idx;   // 玩家编号
    int cards[5];   // 手牌
    int cardNum;   // 几张牌
    float sum;   // 总和
    int computer;   // 是否电脑   1 是 0 否
    float money;   // 赌资
    int vip;   // 是否是 VIP   1 是 0 否
    int out;   // 是否被淘汰   1 是 0 否
} Player;   // 玩家结构体

int decks[4][15] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1}
};

// 牌面显示   t(ten) 10   w 小王   W 大王
char cardsShow[15] = {'A', '2', '3', '4', '5', '6', '7', '8', '9',
                      't', 'J', 'Q', 'K', 'w', 'W'};


// 玩家初始化
Player playerInit(Player player) {
    player.sum = 0;
    player.cardNum = 0;
    return player;
}


// 牌库模式选择/初始化
Deck deckModeChoose(Deck deck) {
    int mode;   // 牌库模式
    printf("选择牌库模式：\n0、自定义牌组模式；1、13 模式；2、4*10 模式；3、52 两小王模式；4、52 大小王模式;\n");
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

    // 点数计算规则定义
    printf("是否开启下列点数计算模式：0、否；1、是；\n");
    printf("自定义牌面权重\n");
    scanf("%d", &mode);
    deck.scoreMode = mode;
    if (mode) {   // 自定义权重
        printf("是否不同牌不同权重\n");
        scanf("%d", &mode);
        deck.scoreMode += mode << 1;
        if (mode) {   // 如果不同权重
            printf("请输入 15 种牌的各自权重\n");
            for (int i = 0; i < 15; ++i) {
                scanf("%f", &deck.weight[i]);
            }
        } else {   // 如果相同权重
            printf("请输入牌的权重\n");
            float tmp;
            scanf("%f", &tmp);
            for (int i = 0; i < 15; ++i) {
                deck.weight[i] = tmp;
            }
        }
    } else {    // 不自定义
        for (int i = 0; i < 15; ++i) {
            deck.weight[i] = 1;
        }
    }
    printf("是否 J、Q、K、王设置为 10\n");
    scanf("%d", &mode);
    deck.scoreMode += mode << 2;
    printf("是否 A 设置为可视情况作 1 和 11\n");
    scanf("%d", &mode);
    deck.scoreMode += mode << 3;
    return deck;
}


// 继续 使代码暂停，直到有任意输入时继续运行，顺便清空控制台
void GoOn(){
    char op[10];
    // 翻页 2 次，第一次使上一个人进入空白页，第二次由下一个人输入，从空白页翻到他的页面，保证看不见他人牌
    for (int i = 0; i < 2; ++i) {
        printf("\n输入任意字符继续\n");
        scanf("%s",op);
        system("cls");   // 清空控制台（在这里就是直接往上翻，使其他人看不见）
    }
}


// 显示玩家当前牌和总点数
void showCards(Player player){
    printf("\n您目前的牌有：\n");
    for (int i = 0; i < player.cardNum; ++i) {
        printf("%c ",cardsShow[player.cards[i]-1]);
    }
    printf("\n您目前的点数总和是：%f\n",player.sum);
}


// 显示当前所有玩家资金
void showMoney(Player players[],int playerNum){
    printf("\n当前各玩家资金如下：\n");
    for (int i = 0; i < playerNum; ++i) {
        printf("%d 号玩家：%f 分\n",i,players[i].money);
    }
}


// 榜单输出
void listOut(Player players[], Deck deck, int playerNum) {
    printf("\n榜单如下：");
    for (int i = 0; i < playerNum; ++i) {
        if (deck.playMode) {
            printf("\n玩家编号 %d 总分 %f\n持有牌面", players[i].idx, players[i].sum);
            for (int j = 0; j < players[i].cardNum; ++j) {
                printf("%c ", cardsShow[players[i].cards[j] - 1]);
            }
        } else {
            printf("\n玩家编号 %d 总分 %f", players[i].idx, players[i].money);
        }
    }
}


// 赌资输入
float stakeInput(Player player){
    float stake;
    scanf("%f", &stake);
    while (stake<=0 || stake>player.money){
        printf("您的赌资输入不合法，赌资应当在大于零且小于您的全部资金，请重新输入\n您的全部资金为 %f\n",player.money);
        scanf("%f", &stake);
    }
    return stake;
}


// 快速排序 - 排玩家手牌
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


// 快速排序 - 按牌面
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


// 分数计算
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


// 游玩过程 - 单次基础游玩
int playBase(Player players[], Deck deck, int playerNum) {
    srand(time(NULL));
    int winner = -1;   // 胜利者
    deck = deckModeChoose(deck);   // 牌库模式选择
//    for (int i = 0; i < 15; ++i) {
//        printf("%d ", deck.cards[i]);
//    }
    // 初始化玩家
    for (int i = 0; i < playerNum; ++i) {
        printf("%d 号玩家初始化完成\n", i);
        players[i] = playerInit(players[i]);
    }

    GoOn();   // 清空控制台

    // 正式游戏
    while (winner < 0) {
        int boom = 0;   // 爆牌人数
        // 用于存放下一波剩余未爆牌玩家应该抽到的牌，配合是否 VIP 使用
        int nextCards[playerNum];
        for (int i = 0; i < playerNum; ++i) {   // 抽牌
            if (players[i].sum < 24 && !players[i].out) {   // 只给未淘汰且未爆牌玩家抽
                int tmp = rand() % 15;
                deck.cards[tmp]--;
                nextCards[i] = tmp + 1;   // 由于牌面是 1-15，而储存是 0-14，故加一
            } else {
                nextCards[i] = 0;
                boom++;
            }
        }

        if (boom < playerNum - 1) {   // 没有很多人爆牌
            // 循环每个人
            for (int i = 0; i < playerNum && winner < 0; ++i) {
                int card = nextCards[i], need = 1;   // 当前抽牌 是否要牌

                if (players[i].sum >= 24 || players[i].out) {   // 爆牌或淘汰直接跳过
                    continue;
                } else {
                    // 先判定是否电脑
                    if (players[i].computer) {
                        // 再判定是否是 VIP
                        if (players[i].vip) {
                            Player tmp = players[i];
                            tmp.cards[tmp.cardNum++] = card;
                            tmp.sum = score(deck, tmp);   // 求分
                            need = tmp.sum > 24 ? 0 : 1;   // 如果加进去后爆牌则不要，否则要
                        } else {
                            need = rand() % 2;
                        }
                    } else {   // 真人
                        if (players[i].vip) {   // 是 VIP
                            printf("%d 号玩家，你的下一张牌是 %c\n", i, cardsShow[card - 1]);
                        }
                        printf("%d 号玩家，你是否要这张牌：\n0、否；1、是\n", i);
                        scanf("%d", &need);
                    }
                }

                if (need) {   // 要牌
                    printf("\n%d 号玩家得到牌 %c，", i, cardsShow[card - 1]);

                    // 加牌
                    players[i].cards[players[i].cardNum++] = card;
                    players[i].sum = score(deck, players[i]);   // 求分
                    printf("%d 号玩家目前有 %d 张牌\n", i, players[i].cardNum);

                    // 情况判定：爆牌、自动胜利、是否开牌
                    if (players[i].sum > 24) {
                        printf("\n%d 号玩家爆了", i);
                        boom++;
                    } else if (players[i].sum == 24) {
                        printf("\n%d 号玩家达到 24 点，自动胜利", i);
                        winner = i;
                    }
                }

                showCards(players[i]);   // 显示角色卡牌和总点数
                GoOn();   // 清空控制台

            }
        } else {   // 爆牌人数过多 未爆牌玩家直接胜利
            for (int i = 0; i < playerNum && winner < 0; ++i) {
                if (players[i].sum < 24) {
                    winner = i;
                }
            }
        }

        // 投票表决是否开牌 -> 大于一半人同意则开牌
        printf("\n请玩家选择是否开牌\n0、否；1、是");
        int votes = 0, tmp;   // 票数 投票人同意与否
        for (int i = 0; i < playerNum; ++i) {
            if (players[i].sum > 24 || players[i].out) { continue; }   // 爆牌或淘汰者跳过
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

        GoOn();   // 清空控制台

    }
    return winner;
}


// 游玩过程 - 赌注模式
int playStake(Player players[], Deck deck, int playerNum, int freq) {
    float stakes[playerNum];
    while (freq--) {
        for (int i = 0; i < playerNum; ++i) {
            printf("请 %d 号玩家输入赌注\n", i);
            stakes[i] = stakeInput(players[i]);
        }
        int winner = playBase(players, deck, playerNum);
        printf("\n本轮 %d 胜利\n\n", winner);
        for (int i = 0; i < playerNum; ++i) {
            if (i == winner) {
                players[i].money += stakes[i] * (float) (playerNum - 1);
            } else {
                players[i].money -= stakes[i];
                players[i].out = players[i].money<=0?1:0;   // 资金小于等于 0 破产淘汰
            }
        }

        showMoney(players,playerNum);   // 输出各玩家剩余资金
        GoOn();   // 清空控制台

    }
    return getWinnerStake(players, playerNum);
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
            printf("%d 号玩家：\n", i);
            players[i].out = 0;
            players[i].idx = i;
            players[i].money = 100;
            printf("  该玩家是： 0、真人； 1、电脑；\n");
            scanf("%d", &players[i].computer);
            printf("  该玩家是否 VIP： 0、否； 1、是；\n");
            scanf("%d", &players[i].vip);
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