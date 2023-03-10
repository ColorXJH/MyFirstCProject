//
// Created by ColorXJH on 2023-03-10.
// 掷色子模拟程序
#include <stdio.h>
#include <stdlib.h>//提供函数rand()的原型
#include "diceroll.h"
int roll_count=0;//外部链接 // 源代码文件中的声明（定义式声明）
//一个变量只能有一个定义式声明，但是带 extern 的声明是引用式声明，可以有多个引用式声明。

//该函数属于文件私有，是roll_n_dice()函数的辅助函数
//掷色子次数和确定面数
static int rollem(int sides){
    int roll;
    roll=rand()%sides+1;
    roll_count++;//计算函数调用次数
    return roll;
}
//返回总点数（掷色子次数和 筛子色子面数）
int roll_n_dice(int dice,int sides){
    int d;
    int total=0;
    if(sides<2){
        printf("needed at least 2 sides.\n");
        return -2;
    }
    if(dice<1){
        printf("needed at least 1 die.\n");
        return -1;
    }
    for ( d = 0; d <dice ; ++d) {
        total+=rollem(sides);
    }
    return total;
    
}
