//
// Created by 86159 on 2023-12-09.
// 中国剩余定理 表达整数的奇怪方式 https://www.acwing.com/problem/content/206/
// 详解 https://www.acwing.com/video/273/
//

#include "stdio.h"
#include "stdbool.h"

typedef long long LL;

int n;
LL a1,m1;
bool has_ans = true;

LL exgcd(LL a,LL b,LL *x, LL *y){
    if(b==0){
        *x = 1,*y = 0;
        return a;
    }

    LL d = exgcd(b,a%b,y,x);
    *y -= a/b*(*x);
    return d;
}

int main(){
    scanf("%d%lld%lld",&n,&a1,&m1);
    LL a2,m2;
    LL k1,k2;
    for (int i = 1; i < n; ++i) {
        scanf("%lld%lld",&a2,&m2);
        LL gcd = exgcd(a1,a2,&k1,&k2);
        if((m2-m1)%gcd){
            has_ans = false;
            break;
        }

        k1 *= (m2-m1)/gcd;
        LL tmp = a2/gcd;
        k1 = (k1%tmp+tmp)%tmp;

        m1 = a1 * k1 + m1;
        a1 = a1/gcd*a2;
        a1 = a1>=0?a1:-a1;
    }

    if(has_ans)printf("%lld\n",(m1%a1+a1)%a1);
    else puts("-1");

    return 0;
}