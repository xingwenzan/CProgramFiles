//
// Created by 86159 on 2024/10/29.
//
#include "stdlib.h"
#include "stdio.h"

int graph[10][10];
int visited[10];

void init(){
    for (int i = 0; i < 10; ++i) {
        visited[i] = 0;
        for (int j = 0; j < 10; ++j) {
            graph[i][j] = i==j;
        }
    }
}

void add(int st, int ed) {
    graph[st][ed] = graph[ed][st] = 1;
}

int judge();
void dfs(int idx);

int main() {
    int a, b;
    init();
    while (1) {
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0)break;
        add(a, b);
    }

    judge()? printf("Yes"): printf("No");
}

int judge(){
    dfs(0);

    for (int i = 0; i < 10; ++i) {
        if(!visited[i])return 0;
    }
    return 1;
}

void dfs(int idx){
    visited[idx] = 1;
    for (int i = 0; i < 10; ++i) {
        if(!visited[i] && graph[idx][i])dfs(i);
    }

}