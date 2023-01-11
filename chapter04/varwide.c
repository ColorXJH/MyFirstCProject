//
// Created by ColorXJH on 2023/1/11.
// 使用变宽输出字段
#include <stdio.h>
int main(void){
    unsigned width,precision;
    int number=256;
    double weight=242.4;
    printf("enter a field width:\n");
    scanf("%d",&width);
    printf("the number is : %*d\n",width,number);
    printf("now enter a width and a precision:\n");
    scanf("%d %d",&width,&precision);
    printf("weight=%*.*f\n",width,precision,weight);
    printf("done!\n");
    return 0;
}

