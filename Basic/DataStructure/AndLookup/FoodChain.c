//
// Created by 86159 on 2023-06-02.
// 食物链 https://www.acwing.com/problem/content/242/
// 解析 https://www.acwing.com/activity/content/code/content/45325/
//

#include "stdio.h"

#define N 50010
int father[N], distance[N];

// 更新祖父节点和距离
int find(int x) {
    if (x != father[x]) {
        // 两种写法都对
        int p = father[x];   // 记录旧的父节点（父）
        father[x] = find(p);   // 旧的父节点更新到祖父节点
        distance[x] += distance[p];   // 子到祖父的距离是子到父距离加父到祖父的距离

//        int p = find(father[x]);   // 记录新父节点（祖父）
//        distance[x] += distance[father[x]];   // 子到祖父的距离是子到父距离加父到祖父的距离
//        father[x] = p;   // 更新父为祖父
    }
    return father[x];
}

int main() {
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
    for (int i = 0; i < k; ++i) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n) {   // 判定条件 2
            ans++;
        } else {
            int px = find(x), py = find(y);   // 记录二者祖父节点
            if (d == 1) {   // 同类的情况下
                if (px == py) {   // 在一条食物链中 - 判定是否冲突
                    if ((distance[x] - distance[y]) % 3) {
                        ans++;
                    }
                } else {   // 不在一条食物链 - 加进去
                    father[px] = py;
                    distance[px] = distance[y] - distance[x];
                }
            } else {   // X 吃 Y 时
                // 注：此时认为距离远等级高，即 3 吃 2，2 吃 1；当将下面的 1 改为 -1 时也对，代表距离近等级高
                if (px == py) {   // 在一条食物链中 - 判定是否冲突
                    if ((distance[x] - distance[y] - 1) % 3) {
                        ans++;
                    }
                } else {   // 不在一条食物链 - 加进去
                    father[px] = py;
                    distance[px] = distance[y] + 1 - distance[x];
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}