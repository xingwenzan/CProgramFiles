//
// Created by 86159 on 2023-06-25.
// 走迷宫 https://www.acwing.com/problem/content/846/
//
#include "stdio.h"
#include "stdbool.h"

#define N 10010
int queue[N][2], head = 0, tail = 0;
int maze[110][110], n, m, distance[110][110];
int X[4] = {0, 1, 0, -1}, Y[4] = {1, 0, -1, 0};

bool empty() {
    return head >= tail ? true : false;
}

void add(int x, int y) {
    queue[tail][0] = x;
    queue[tail][1] = y;
    tail++;
}

int bfs() {
    distance[0][0] = 0;
    add(0, 0);
    while (!empty()) {
        int x = queue[head][0], y = queue[head][1];
        head++;
        for (int i = 0; i < 4; ++i) {
            int tmpX = x + X[i], tmpY = y + Y[i];
            if (tmpX >= 0 && tmpX < n && tmpY >= 0 && tmpY < m && maze[tmpX][tmpY] == 0 && distance[tmpX][tmpY] == -1) {
                add(tmpX, tmpY);
                distance[tmpX][tmpY] = distance[x][y] + 1;
            }
        }
    }
    return distance[n-1][m-1];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &maze[i][j]);
            distance[i][j] = -1;
        }
    }
    printf("%d", bfs());
    return 0;
}