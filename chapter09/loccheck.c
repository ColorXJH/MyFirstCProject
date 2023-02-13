//
// Created by ColorXJH on 2023-02-13.
// 查看变量被存储在何处
#include <stdio.h>
void makeLocation(int);
int main(void){
    int num=2,bath=5;
    //%p是输出地址的转换说明
    printf("in main(),num =%d and location is%p\n",num,&num);
    printf("in main(),bath =%d and location is%p\n",bath,&bath);
    makeLocation(bath);
    return 0;
}
void makeLocation(int bath){
    int num=10;
    printf("in makeLocation(),num =%d and location is%p\n",num,&num);
    printf("in makeLocation(),bath =%d and location is%p\n",bath,&bath);
}

