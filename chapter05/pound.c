//
// Created by ColorXJH on 2023/1/30.
// 定义一个带参数的函数
#include <stdio.h>
void pound(int n);
int main(void){
    int times=5;
    char ch='!';//ASCII 33
    float f=6.0f;
    pound(times);
    //类型转换
    pound(ch);//==>pound((int)ch)
    pound(f);//==>pound((int)f)
    return 0;
}

void pound(int n){
    while(n-->0){
        printf("#");
    }
    printf("\n");
}

