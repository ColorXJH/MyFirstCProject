//
// Created by ColorXJH on 2023/1/12.
// 计算多个不同鞋码对应的脚长
#include <stdio.h>
#define ADJUST 7.31
int main(void){
    const double SCALE=0.333;
    double shoe,foot;
    printf("shoe size foot length\n");
    shoe=3.0;
    while (shoe<18.5){
        foot=SCALE*shoe+ADJUST;
        printf("%10.1f  %15.2f inches\n",shoe,foot);
        shoe=shoe+1.0;
    }
    printf("if the shoe fit,wear it'\n");
    return 0;
}

