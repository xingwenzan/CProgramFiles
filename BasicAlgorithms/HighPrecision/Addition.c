//
// Created by 86159 on 2023-03-31.
// 高精度加法 https://www.acwing.com/problem/content/793/
//

#include <stdio.h>
#include <string.h>

int main ()
{
    char a[100010];
    char b[100010];
    int A[100100];
    int B[100010];
    scanf("%s %s",a,b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    int j = 0;
    int i = 0;
    for( i = lenA - 1 , j = 0; i >= 0 ; i-- , j ++) A[j] = a[i] - '0';
    for( i = lenB - 1, j = 0; i >= 0 ; i--, j ++) B[j] = b[i] - '0';

    int C[100010];
    int t = 0;
    for( i = 0;i < lenA || i < lenB;i ++) {
        if(i < lenA) t += A[i];
        if(i < lenB) t += B[i];
        C[i] = t % 10;
        t /= 10;
    }

    if(t != 0) {
        C[i] = t;
        for(j = i ; j >= 0 ; j --) printf("%d",C[j]);
    }
    else for(j = i - 1; j >= 0 ; j --) printf("%d",C[j]);
    return 0;
}
