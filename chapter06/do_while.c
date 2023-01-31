//
// Created by ColorXJH on 2023-01-31.
// 出口条件循环（相比于 while  for这类入口条件循环）
#include <stdio.h>
int main(void){
    const int secret_code=13;
    int code_entered;
    do{
        printf("to enter the right number\n");
        scanf("%d",&code_entered);
    } while (code_entered!=secret_code);
    printf("congratulation! your are right");
    return 0;
}

