//
// Created by ColorXJH on 2023/1/4.
// 显示字符的代码编号
#include <stdio.h>
int main(void){
    char ch;
    printf("please enter a character.\n");
    scanf("%c",&ch);//用户输入字符
    printf("the code for %c is %d.\n",ch,ch);
    return 0;
}

