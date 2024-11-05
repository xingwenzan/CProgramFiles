//
// Created by 86159 on 2024/11/5.
//
#include "stdlib.h"
#include "stdio.h"

#define MAX 7

typedef struct Arc{
    int idx;
    struct Arc*next;
}Arc;

typedef struct Node{
//    int idx;
    int weight;
    Arc *first;
}Node,Nodes[MAX];

typedef struct Graph{
    int nodeNum;
    int arcNum;
    Nodes nodes;
}Graph;

void init(Graph *graph, int node){
    graph->nodeNum = node;
    graph->arcNum = 0;
    for (int i = 0; i < node; ++i) {
        graph->nodes[i].first = NULL;
    }
}

void add(Graph *graph,int st,int ed){
    Arc *tmp = (Arc*) malloc(sizeof (Arc));
    tmp->idx = ed;
    tmp->next = graph->nodes[st].first;
    graph->nodes[st].first = tmp;

    tmp = (Arc*) malloc(sizeof (Arc));
    tmp->idx = st;
    tmp->next = graph->nodes[ed].first;
    graph->nodes[ed].first = tmp;
}

int getMaxIdx(Graph*graph);
int dfs(Graph *graph,int *visited,int idx);

int main(){
    Graph *g = (Graph*) malloc(sizeof(Graph));
    init(g,MAX);
    printf("读取权值:\n");
    for (int i = 0; i < g->nodeNum; ++i) {
        scanf("%d",&g->nodes[i].weight);
    }
    printf("\n画边:\n");
    int a,b;
    while (1){
        scanf("%d%d",&a,&b);
        if(a==b)break;
        add(g,a,b);
    }

    int ans = getMaxIdx(g);
    printf("\n权值最大点：%d\n最大权值：%d",ans,g->nodes[ans].weight);
}

int getMaxIdx(Graph*graph){
    int visited[graph->nodeNum];
    for (int i = 0; i < graph->nodeNum; ++i) {
        visited[i] = 0;
    }
    int ans = -1,tmp;
    for (int i = 0; i < graph->nodeNum; ++i) {
        if(!visited[i]){
            tmp = dfs(graph,visited,i);
            ans = ans!=-1 && graph->nodes[ans].weight>=graph->nodes[tmp].weight?ans:tmp;
        }
    }
    return ans;
}

int dfs(Graph *graph,int *visited,int idx){
    Arc *p = graph->nodes[idx].first;
//    if(p==NULL)return idx;
    visited[idx] =1;
    int ans = idx,tmp;
    while (p!=NULL){
        if(!visited[p->idx]){
//            ans = graph->nodes[ans].weight>=graph->nodes[p->idx].weight?ans:p->idx;
//            visited[p->idx] = 1;
            tmp = dfs(graph,visited,p->idx);
            ans = graph->nodes[ans].weight>=graph->nodes[tmp].weight?ans:tmp;
        }
        p = p->next;
    }
    return ans;
}