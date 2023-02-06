//
// Created by ColorXJH on 2023-02-06.
// 使用break退出循环
#include <stdio.h>
int main(void){
    float length,width;
    printf("enter the length of the rectangle:\n");
    while(scanf("%f",&length)==1){
        printf("length=%0.2f:\n",length);
        printf("enter its width:\n");
        if(scanf("%f",&width)!=1){
            break;
        }
        printf("width=%0.2f:\n",width);
        printf("area=%0.2f:\n",length*width);
        printf("enter the length:\n");
    }
    printf("done!");
    return 0;
}

