//
// Created by 86159 on 2023-04-25.
// 编写程序，输入任意三个不同且小于 10 的整数数字，输出三个数字所有且不 相同的排列方式。要求写出程序语句，并粘贴任意三个数字的运行结果截图。
//
#include "stdio.h"
int a[3];

int main(){
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(j!=i && k!=i && k!=j){
                    printf("%d%d%d\n",a[i],a[j],a[k]);
                }
            }
        }
    }
    printf("\n20212703411 张馨文");
    return 0;
}