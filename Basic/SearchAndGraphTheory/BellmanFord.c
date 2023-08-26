//
// Created by 86159 on 2023-08-26.
// 有边数限制的最短路 https://www.acwing.com/problem/content/855/
//

#include "stdio.h"
#include "string.h"

#define N 510
#define M 10010
#define INF 0x3f3f3f3f
#define min(a, b) ((a)<(b)?(a):(b))
typedef struct {
    int start;
    int end;
    int length;
} Edge;

Edge edge[M];
int d[N], last[N];
int n, m, k;

void BF() {
    for (int i = 0; i < k; ++i) {
        memcpy(last, d, sizeof d);
        for (int j = 0; j < m; ++j) {
            Edge e = edge[j];
            d[e.end] = min(d[e.end], last[e.start] + e.length);
        }
    }
}

int main() {
    memset(d, INF, sizeof d);
    d[1] = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edge[i].start, &edge[i].end, &edge[i].length);
    }

    BF();

    if (d[n] > INF / 2)printf("impossible");
    else printf("%d", d[n]);

    return 0;
}