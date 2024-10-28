//
// Created by 86159 on 2024/10/28.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct ARC {
    int nodeIdx;
    struct ARC *next;
} ARC;

typedef struct Node {
    int data;
    struct ARC *first;
} Node, NODES[10];

typedef struct GRAPH {
    int NodeNum;
    int ArcNum;
    NODES nodes;
    int visited[10];
} GRAPH;

int init(GRAPH *graph) {
    if (graph == NULL)return 1;

    graph->NodeNum = 0;
    graph->ArcNum = 0;
    for (int i = 0; i < 10; ++i) {
        graph->nodes[i].data = i;
        graph->nodes[i].first = NULL;
        graph->visited[i] = 0;
    }
    return 0;
}

void add(GRAPH *graph, int st, int ed) {
    ARC *tmp = (ARC *) malloc(sizeof(ARC));
    tmp->nodeIdx = ed;
    tmp->next = graph->nodes[st].first;
    graph->nodes[st].first = tmp;
}


void BFS(GRAPH *graph, int idx);

void useBFS(GRAPH *graph);


int main() {
    GRAPH *g = (GRAPH *) malloc(sizeof(GRAPH));

    if (init(g)) {
        printf("Error");
        return 0;
    }

    int a, b;
    scanf("%d%d", &a, &b);
    g->NodeNum = a;
    g->ArcNum = b;
    for (int i = 0; i < g->ArcNum; ++i) {
        scanf("%d%d", &a, &b);
        add(g, a, b);
    }

    useBFS(g);

    return 0;
}

void BFS(GRAPH *graph, int idx) {
    int queue[10], h = 0, t = 0, tmp;
    for (int i = 0; i < 10; ++i) {
        queue[i] = -1;
    }
    queue[t] = idx;
    t = (t + 1) % 10;

    ARC *p;
    while (h != t) {
        tmp = queue[h++];
        h %= 10;

        printf("idx: %d, data: %d\n", tmp, graph->nodes[tmp].data);
        graph->visited[tmp] = 1;

        p = graph->nodes[tmp].first;
        while (p != NULL) {
            tmp = p->nodeIdx;
            if (graph->visited[tmp] == 0) {
                queue[t] = tmp;
                t = (t + 1) % 10;
            }
            p = p->next;
        }
    }
}

void useBFS(GRAPH *graph) {
    for (int i = 0; i < (graph->NodeNum); ++i) {
        if (graph->visited[i] == 0)BFS(graph, i);
    }
}