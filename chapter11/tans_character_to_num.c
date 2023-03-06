//
// Created by ColorXJH on 2023-03-06.
// 把命令行参数转化为数字
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    int i,times;
    if(argc<2||(times= atoi(argv[1]))<1){
        printf("usage: %s positive-number\n",argv[0]);
    } else{
        for (i = 0;  i< times; i++) {
            puts("hello,my name is color_xjh");
        }
    }
    return 0;
}

