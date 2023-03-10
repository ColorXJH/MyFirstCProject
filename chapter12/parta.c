//
// Created by ColorXJH on 2023-03-10.
// 不同的存储类别
#include <stdio.h>
#include "partb.c"
void report_count();
void accumulate(int k);
int count=0;//文件作用域，外部链接
int main(void){
    int value;//自动变量
    int register i;//寄存器变量
    printf("enter a positive integer (0 to quit):\n");
    while (scanf("%d",&value)==1&&value>0){
        ++count;//使用文件作用域变量
        for (int i = value; i>=0 ; --i) {
            accumulate(i);
        }
        printf("enter a positive integer (0 to quit):\n");
    }
    report_count();
    return 0;
}
void report_count(){
    printf("loop executed %d times",count);
}

