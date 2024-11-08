//
// Created by 86159 on 2024/11/8.
//
#include "stdlib.h"
#include "stdio.h"

#define MAX 10

typedef struct Graph{
    int NodesNum;
    int Table[MAX][MAX];
}Graph;

void init(Graph *graph,int num){
    graph->NodesNum = num;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            graph->Table[i][j] = 0;
        }
    }
}

void add(Graph *graph,int st,int ed){
    graph->Table[st][ed] = 1;
}

void getPath(Graph *graph,int start,int end);
void dfs(Graph *graph,int *stack,int *idx,int *visited,int cur,int end);

int main(){
    Graph *g = (Graph*) malloc(sizeof(Graph));
    int a,b;
    printf("点数：");
    scanf("%d",&a);
    init(g,a);
    printf("画图：");
    while (1){
        scanf("%d%d",&a,&b);
        if(a==b)break;
        add(g,a,b);
    }
    printf("目标：");
    scanf("%d%d",&a,&b);
    getPath(g,a,b);
}

void getPath(Graph *graph,int start,int end){
    if(graph==NULL)return;
    if(end>=graph->NodesNum || start<0){
        printf("NULL");
        return;
    }
    int stack[graph->NodesNum],visited[graph->NodesNum];
    for (int i = 0; i < graph->NodesNum; ++i) {
        stack[i] = -1;visited[i] = 0;
    }
    int *idx = (int *) malloc(sizeof(int ));
    *idx = 1;
    stack[0] = start;
    dfs(graph,stack,idx,visited,start,end);
}

void dfs(Graph *graph,int *stack,int *idx,int *visited,int cur,int end){
    for (int i = 0; i < graph->NodesNum; ++i) {
        if(!visited[i] && graph->Table[cur][i]){
            stack[*idx] = i;
            if(stack[*idx]==end){
                for (int j = 0; j <= (*idx); ++j) {
                    printf("%d ",stack[j]);
                }
                printf("\n");
                continue;
            }
            visited[i] = 1;
            (*idx)++;
            dfs(graph,stack,idx,visited,i,end);
            stack[*idx] = -1;visited[i] = 0;
            (*idx)--;
        }

    }
}