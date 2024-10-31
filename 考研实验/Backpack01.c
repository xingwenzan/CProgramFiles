//
// Created by 86159 on 2024/10/31.
//
#include "stdio.h"

int N, V;

int main() {

    scanf("%d%d", &N, &V);

    int value[N], volume[N], ans[V + 1];

    for (int i = 0; i < V + 1; ++i) {
        ans[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &volume[i], &value[i]);
//        printf("%d %d\n",value[i],volume[i]);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = V; j >= volume[i]; --j) {
            ans[j] = ans[j] >= ans[j - volume[i]] + value[i] ? ans[j] : ans[j - volume[i]] + value[i];
        }
    }

    printf("%d", ans[V]);

}