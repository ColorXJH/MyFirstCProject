//
// Created by ColorXJH on 2023/1/9.
// 字段宽度
#include <stdio.h>
#define PAGES 959
int main(void){
    printf("*%d*\n",PAGES);//*959*
    printf("*%2d*\n",PAGES);//*959*
    printf("*%10d*\n",PAGES);//*       959*
    printf("*%-10d*\n",PAGES);//*959       *
    return 0;
}

