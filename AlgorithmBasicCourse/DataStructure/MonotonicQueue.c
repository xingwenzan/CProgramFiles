//
// Created by 86159 on 2023-05-07.
// 滑动窗口 https://www.acwing.com/problem/content/156/
//

#include "stdio.h"
#include "stdbool.h"
#define N 1000010

/*
 * queue 存索引
 * lst 存原数组
 */
int queue[N],lst[N],headPointer,tailPointer;

void init(){
    headPointer = 0;
    tailPointer = -1;
}

// 尾索引小于头索引为空
bool isEmpty(){
    return headPointer>tailPointer;
}

// 砍头 头索引后移
void popHead(){
    headPointer++;
}

// 断尾 尾索引前移
void popTail(){
    tailPointer--;
}

// 返回队列头的值 对应队列最前面的值在原数组中的位置
int head(){
    return queue[headPointer];
}

// 返回队列尾的值 对应队列最后面的值在原数组中的位置
int tail(){
    return queue[tailPointer];
}

// 向队列里添加元素
void push(int x){
    queue[++tailPointer] = x;
}

void minWindows(int length,int window){
    init();
    for (int i = 0; i < length; ++i) {
        // 队列不空且头对应位置在窗口外 去头
        if((!isEmpty()) && (head()<i-window+1)){
            popHead();
        }
        // 队列不空且新来的比队列尾在原数组的值小 去尾
        while ((!isEmpty()) && (lst[i]<lst[tail()])){
            popTail();
        }
        push(i);
        if (i>=window-1){
            printf("%d ",lst[head()]);
        }
    }
    printf("\n");
}

void maxWindows(int length,int window){
    init();
    for (int i = 0; i < length; ++i) {
        // 队列不空且头对应位置在窗口外 去头
        if((!isEmpty()) && (head()<i-window+1)){
            popHead();
        }
        // 队列不空且新来的比队列尾在原数组的值大 去尾
        while ((!isEmpty()) && (lst[i]>lst[tail()])){
            popTail();
        }
        push(i);
        if (i>=window-1){
            printf("%d ",lst[head()]);
        }
    }
    printf("\n");
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&lst[i]);
    }
    minWindows(n,k);
    maxWindows(n,k);
}