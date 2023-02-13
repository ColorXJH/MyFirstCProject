//
// Created by ColorXJH on 2023-02-13.
// 第一个版本的交换函数
#include <stdio.h>
void interChange(int i,int v);
int main(void){
    int x=5,y=10;
    printf("now x=%d and y=%d\n",x,y);
    interChange(x,y);
    printf("now x=%d and y=%d\n",x,y);
    return 0;
}
//变量值传递，函数返回时的变量并不是main中的变量，交换并不会返回原函数
void interChange(int i,int v){
    int temp;
    temp=i;
    i=v;
    v=temp;
}
