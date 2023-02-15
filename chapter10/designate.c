//
// Created by ColorXJH on 2023-02-15.
// 使用指定初始化器
#include <stdio.h>
#define MONTHS 12
int main(void){
    //指定初始化位置之前的，没有指定的会置0，之后的按照顺序初始化，再次指定初始化会覆盖之前的值
    int days[MONTHS]={31,28,[4]=31,30,31,[1]=29};//先声明，再赋值也不起作用
    int i;
    for(i=0;i<MONTHS;i++){
        printf("%2d   %d\n",i+1,days[i]);
    }
    //int stuff[] = {1, [6] = 23};　有7个元素，{1,0,0,0,0,0,23}
    //int staff[] = {1, [6] = 4, 9, 10};//有9个元素{1,0,0,0,0,0,4,9,10}
    return 0;
}

