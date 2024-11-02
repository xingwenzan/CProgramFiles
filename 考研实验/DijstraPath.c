//
// Created by 86159 on 2024/11/2.
//
#include "stdio.h"

#define INF 0x0f0f0f0f

int dist[6][6];
int visited[6], length[6], path[6];

void init() {
    for (int i = 0; i < 6; ++i) {
        visited[i] = 0;
        path[i] = -1;
        length[i] = INF;
        for (int j = 0; j < 6; ++j) {
            dist[i][j] = i == j ? 0 : INF;
        }
    }
}

void getPath();

void outPath();

int main() {
    init();

    int st, ed, len;
    while (1) {
        scanf("%d%d%d", &st, &ed, &len);
        if (!st && !ed && !len)break;
        dist[st][ed] = len;
    }

    getPath();
    outPath();
}

void getPath() {

    for (int i = 0; i < 6; ++i) {
        length[i] = dist[0][i];
        if(length[i] != 0 && length[i] != INF)path[i] = 0;
    }
    visited[0] = 1;

    int mid, tmp = INF;

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (!visited[j] && tmp > length[j]) {
                mid = j;
                tmp = length[j];
            }
        }

        visited[mid] = 1;

        for (int j = 0; j < 6; ++j) {
            tmp = length[mid] + dist[mid][j];
            if (length[j] > tmp) {
                length[j] = tmp;
                path[j] = mid;
            }
        }
    }
}

void outPath() {
    for (int i = 0; i < 6; ++i) {
        printf("\n0 -> %d: %d ", i,i);
        int tmp = i;
        while (path[tmp] != -1) {
            printf("%d ", path[tmp]);
            tmp = path[tmp];
        }
        printf("\nlength: %d",length[i]);
    }

}